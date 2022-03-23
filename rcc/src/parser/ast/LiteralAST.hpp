#ifndef __parser__ast__LiteralAST
#define __parser__ast__LiteralAST

#include <deque>

#include "lexer/lexer.hpp"

#include "ASTNode.hpp"

namespace parser::ast {

  class LiteralAST: public ASTNode {
  public:
    static unique_ptr<LiteralAST> parse(deque<lexer::Token>& tokens);
  };

}

#endif