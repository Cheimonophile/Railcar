#ifndef __parser__ast__TypeAST
#define __parser__ast__TypeAST

#include "ASTNode.hpp"

#include "lexer/tokens.hpp"

#include <deque>

namespace parser::ast {


  class TypeAST: public ASTNode {
    vector<lexer::Token> uuname;
  public:
    static unique_ptr<TypeAST> parse(deque<lexer::Token>& tokens);
  };





}

#endif