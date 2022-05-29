#include <iostream>

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"

#include "llvm/ADT/APInt.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "visitorimpl.h"

visitor_impl::visitor_impl(llvm::LLVMContext *context, llvm::Module *module)
{
    assert(context && module);
    context_ = context;
    module_ = module;
}

antlrcpp::Any visitor_impl::visitMulDivExpression(grootParser::MulDivExpressionContext *ctx)
{
    auto op = ctx->op->getText();
    assert(!op.empty());

    auto left = visit(ctx->left).as<llvm::Value *>();
    auto right = visit(ctx->right).as<llvm::Value *>();

    switch (op[0])
    {
    case '*':
        return builder_->CreateMul(left, right);
    case '/':
        return builder_->CreateUDiv(left, right); // TODO: handle division by zero (or not - we are building a compiler)
    default:
        assert(false);
    }
}

antlrcpp::Any visitor_impl::visitAddSubExpression(grootParser::AddSubExpressionContext *ctx)
{
    auto op = ctx->op->getText();
    assert(!op.empty());

    auto left = visit(ctx->left).as<llvm::Value *>();
    auto right = visit(ctx->right).as<llvm::Value *>();

    switch (op[0])
    {
    case '+':
        return builder_->CreateAdd(left, right);
    case '-':
        return builder_->CreateSub(left, right);
    default:
        assert(false);
    }
}

antlrcpp::Any visitor_impl::visitPrimitiveExpression(grootParser::PrimitiveExpressionContext *ctx)
{
    auto val = std::stoi(ctx->atom->getText());
    return (llvm::Value *)(llvm::ConstantInt::get(*context_, llvm::APInt(64, val)));
}

antlrcpp::Any visitor_impl::visitReturnStatement(grootParser::ReturnStatementContext *ctx)
{
    auto result = visit(ctx->expr).as<llvm::Value *>();
    return builder_->CreateRet(result);
}

antlrcpp::Any visitor_impl::visitVariableAssignment(grootParser::VariableAssignmentContext *ctx)
{
    auto val = visit(ctx->expr).as<llvm::Value *>();
    auto varName = ctx->var_name->getText();
    auto varType = llvm::Type::getInt64Ty(*context_);
    auto alloca = allocateVariable(varName, varType);

    scope_[varName] = alloca;

    return (llvm::StoreInst *)builder_->CreateStore(val, alloca, false);
    // return builder_->CreateLoad(val->getType(), alloca, varName.c_str());
}

antlrcpp::Any visitor_impl::visitVariableValueExpression(grootParser::VariableValueExpressionContext *ctx)
{
    auto varName = ctx->name->getText();
    auto alloca = scope_[varName];
    auto varType = llvm::Type::getInt64Ty(*context_);

    return (llvm::Value *)builder_->CreateLoad(varType, alloca, varName.c_str());
}

antlrcpp::Any visitor_impl::visitFunctionDefStatement(grootParser::FunctionDefStatementContext *ctx)
{
    // @TODO: Creation of unique pointers in this class causes issues with ths LLVM internal memory mangement
    // we will probably need to cleanup LLVM first before this class go out of scope. 
    // For now we are alocating the memort and let it leak.

    auto fname = ctx->name->getText();

    auto intType = llvm::Type::getInt32Ty(*context_);
    auto funPrototype = llvm::FunctionType::get(intType, {}, false);
    fun_ = llvm::Function::Create(funPrototype, llvm::Function::ExternalLinkage, fname, module_);

    // 3. Extract the function parameters to be used with instructions - @TODO

    // 4. Create function body block structure
    block_temp_ = llvm::BasicBlock::Create(*context_, fname + "Block", fun_);

    // 5. Create instructions for the block
    builder_ = new llvm::IRBuilder<>(block_temp_);

    return visit(ctx->blk);
}

// Helper functions

llvm::AllocaInst *visitor_impl::allocateVariable(const std::string &varName, llvm::Type *varType)
{
    assert(fun_ != nullptr);
    llvm::IRBuilder<> bld(&fun_->getEntryBlock(), fun_->getEntryBlock().begin());
    return bld.CreateAlloca(varType, 0, varName.c_str());
}
