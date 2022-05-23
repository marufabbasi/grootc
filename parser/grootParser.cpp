
// Generated from groot.g4 by ANTLR 4.9.3


#include "grootVisitor.h"

#include "grootParser.h"


using namespace antlrcpp;
using namespace antlr4;

grootParser::grootParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

grootParser::~grootParser() {
  delete _interpreter;
}

std::string grootParser::getGrammarFileName() const {
  return "groot.g4";
}

const std::vector<std::string>& grootParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& grootParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

grootParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

grootParser::ExpressionContext* grootParser::ProgramContext::expression() {
  return getRuleContext<grootParser::ExpressionContext>(0);
}


size_t grootParser::ProgramContext::getRuleIndex() const {
  return grootParser::RuleProgram;
}


antlrcpp::Any grootParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<grootVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

grootParser::ProgramContext* grootParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, grootParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    antlrcpp::downCast<ProgramContext *>(_localctx)->expr = expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

grootParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t grootParser::ExpressionContext::getRuleIndex() const {
  return grootParser::RuleExpression;
}

void grootParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrimitiveExpressionContext ------------------------------------------------------------------

tree::TerminalNode* grootParser::PrimitiveExpressionContext::INT() {
  return getToken(grootParser::INT, 0);
}

grootParser::PrimitiveExpressionContext::PrimitiveExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any grootParser::PrimitiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<grootVisitor*>(visitor))
    return parserVisitor->visitPrimitiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExpressionContext ------------------------------------------------------------------

std::vector<grootParser::ExpressionContext *> grootParser::MulDivExpressionContext::expression() {
  return getRuleContexts<grootParser::ExpressionContext>();
}

grootParser::ExpressionContext* grootParser::MulDivExpressionContext::expression(size_t i) {
  return getRuleContext<grootParser::ExpressionContext>(i);
}

grootParser::MulDivExpressionContext::MulDivExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any grootParser::MulDivExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<grootVisitor*>(visitor))
    return parserVisitor->visitMulDivExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExpressionContext ------------------------------------------------------------------

std::vector<grootParser::ExpressionContext *> grootParser::AddExpressionContext::expression() {
  return getRuleContexts<grootParser::ExpressionContext>();
}

grootParser::ExpressionContext* grootParser::AddExpressionContext::expression(size_t i) {
  return getRuleContext<grootParser::ExpressionContext>(i);
}

grootParser::AddExpressionContext::AddExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any grootParser::AddExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<grootVisitor*>(visitor))
    return parserVisitor->visitAddExpression(this);
  else
    return visitor->visitChildren(this);
}

grootParser::ExpressionContext* grootParser::expression() {
   return expression(0);
}

grootParser::ExpressionContext* grootParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  grootParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  grootParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, grootParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<PrimitiveExpressionContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(7);
    antlrcpp::downCast<PrimitiveExpressionContext *>(_localctx)->atom = match(grootParser::INT);
    _ctx->stop = _input->LT(-1);
    setState(17);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(15);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(9);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(10);
          antlrcpp::downCast<MulDivExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == grootParser::T__0

          || _la == grootParser::T__1)) {
            antlrcpp::downCast<MulDivExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(11);
          antlrcpp::downCast<MulDivExpressionContext *>(_localctx)->right = expression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(12);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(13);
          antlrcpp::downCast<AddExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == grootParser::T__2

          || _la == grootParser::T__3)) {
            antlrcpp::downCast<AddExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(14);
          antlrcpp::downCast<AddExpressionContext *>(_localctx)->right = expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(19);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool grootParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool grootParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> grootParser::_decisionToDFA;
atn::PredictionContextCache grootParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN grootParser::_atn;
std::vector<uint16_t> grootParser::_serializedATN;

std::vector<std::string> grootParser::_ruleNames = {
  "program", "expression"
};

std::vector<std::string> grootParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> grootParser::_symbolicNames = {
  "", "", "", "", "", "INT", "WHITEPACE"
};

dfa::Vocabulary grootParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> grootParser::_tokenNames;

grootParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x8, 0x17, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x12, 0xa, 0x3, 0xc, 
       0x3, 0xe, 0x3, 0x15, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 
       0x4, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x2, 0x16, 
       0x2, 0x6, 0x3, 0x2, 0x2, 0x2, 0x4, 0x8, 0x3, 0x2, 0x2, 0x2, 0x6, 
       0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 0x3, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 
       0x8, 0x3, 0x1, 0x2, 0x9, 0xa, 0x7, 0x7, 0x2, 0x2, 0xa, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0xb, 0xc, 0xc, 0x5, 0x2, 0x2, 0xc, 0xd, 0x9, 0x2, 
       0x2, 0x2, 0xd, 0x12, 0x5, 0x4, 0x3, 0x6, 0xe, 0xf, 0xc, 0x4, 0x2, 
       0x2, 0xf, 0x10, 0x9, 0x3, 0x2, 0x2, 0x10, 0x12, 0x5, 0x4, 0x3, 0x5, 
       0x11, 0xb, 0x3, 0x2, 0x2, 0x2, 0x11, 0xe, 0x3, 0x2, 0x2, 0x2, 0x12, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 
       0x3, 0x2, 0x2, 0x2, 0x14, 0x5, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 
       0x2, 0x2, 0x2, 0x4, 0x11, 0x13, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

grootParser::Initializer grootParser::_init;
