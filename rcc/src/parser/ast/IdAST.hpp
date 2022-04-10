#ifndef __parser__ast__IdAST
#define __parser__ast__IdAST

#include "ASTNode.hpp"

#include "lexer/tokens.hpp"

#include <deque>

namespace parser::ast {


  class IdAST: public ASTNode {
    vector<lexer::Token> ids;
  public:
    static unique_ptr<IdAST> parse(deque<lexer::Token>& tokens);
  };





}

#endif