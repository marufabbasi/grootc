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

visitor_impl::visitor_impl(llvm::LLVMContext *context, llvm::IRBuilder<> *builder)
{
    builder_ = builder;
    context_ = context;
}

antlrcpp::Any visitor_impl::visitProgram(grootParser::ProgramContext *ctx)
{
    auto result = visit(ctx->expr).as<llvm::Value*>();
    return builder_->CreateRet(result);
}

antlrcpp::Any visitor_impl::visitMulDivExpression(grootParser::MulDivExpressionContext *ctx)
{
    auto op = ctx->op->getText();
    assert(!op.empty());

    auto left = visit(ctx->left).as<llvm::Value*>();
    auto right = visit(ctx->right).as<llvm::Value*>();

    switch (op[0])
    {
    case '*':
        return builder_->CreateMul(left, right);
    case '/':
        return builder_->CreateFDiv(left, right); // TODO: handle division by zero (or not - we are building a compiler)
    default:
        assert(false);
    }
}

antlrcpp::Any visitor_impl::visitAddExpression(grootParser::AddExpressionContext *ctx)
{
    auto op = ctx->op->getText();
    assert(!op.empty());

    auto left = visit(ctx->left).as<llvm::Value*>();
    auto right = visit(ctx->right).as<llvm::Value*>();

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
    return (llvm::Value*) (llvm::ConstantInt::get(*context_, llvm::APInt(64, val)));
}
