#ifndef __parser__ast__NatLiteralAST
#define __parser__ast__NatLiteralAST

#include <deque>

#include "lexer/lexer.hpp"

#include "ASTNode.hpp"

#include "LiteralAST.hpp"

namespace parser::ast {

  class NatLiteralAST: public LiteralAST {
  public:
    static unique_ptr<NatLiteralAST> parse(deque<lexer::Token>& tokens);
  };

}

#endif