#ifndef _GROOT_VISITOR_IMPL_
#define _GROOT_VISITOR_IMPL_

#include <map>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"

#include "parser/grootBaseVisitor.h"

class visitor_impl : public grootBaseVisitor
{
public:
    visitor_impl(llvm::LLVMContext *context, llvm::Function *fun, llvm::IRBuilder<> *builder);

    antlrcpp::Any visitPrimitiveExpression(grootParser::PrimitiveExpressionContext *ctx) override;
    antlrcpp::Any visitMulDivExpression(grootParser::MulDivExpressionContext *ctx) override;
    antlrcpp::Any visitAddSubExpression(grootParser::AddSubExpressionContext *ctx) override;

    antlrcpp::Any visitReturnStatement(grootParser::ReturnStatementContext *ctx) override;
    antlrcpp::Any visitVariableAssignment(grootParser::VariableAssignmentContext *ctx) override;
    antlrcpp::Any visitVariableValueExpression(grootParser::VariableValueExpressionContext *ctx) override;

protected:
    llvm::AllocaInst* allocateVariable(const std::string &VarName, llvm::Type *varType);

private:
    llvm::IRBuilder<> *builder_;
    llvm::LLVMContext *context_;
    llvm::Function *fun_;

    std::map<std::string, llvm::AllocaInst*> scope_;
};

#endif

