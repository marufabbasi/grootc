
// Generated from groot.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "grootVisitor.h"


/**
 * This class provides an empty implementation of grootVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  grootBaseVisitor : public grootVisitor {
public:

  virtual antlrcpp::Any visitProgram(grootParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimitiveExpression(grootParser::PrimitiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulDivExpression(grootParser::MulDivExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddExpression(grootParser::AddExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

