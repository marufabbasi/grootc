#ifndef _GROOT_VISITOR_IMPL_
#define _GROOT_VISITOR_IMPL_

#include "llvm/IR/IRBuilder.h"
#include "parser/grootBaseVisitor.h"

class visitor_impl : public grootBaseVisitor
{
public:
    visitor_impl(llvm::LLVMContext *context, llvm::IRBuilder<> *builder);

    antlrcpp::Any visitProgram(grootParser::ProgramContext *ctx) override;
    antlrcpp::Any visitPrimitiveExpression(grootParser::PrimitiveExpressionContext *ctx) override;
    antlrcpp::Any visitMulDivExpression(grootParser::MulDivExpressionContext *ctx) override;
    antlrcpp::Any visitAddExpression(grootParser::AddExpressionContext *ctx) override;

private:
    llvm::IRBuilder<> *builder_;
    llvm::LLVMContext *context_;
};

#endif

