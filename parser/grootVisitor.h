
// Generated from groot.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "grootParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by grootParser.
 */
class  grootVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by grootParser.
   */
    virtual antlrcpp::Any visitProgram(grootParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitPrimitiveExpression(grootParser::PrimitiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMulDivExpression(grootParser::MulDivExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAddExpression(grootParser::AddExpressionContext *context) = 0;


};

