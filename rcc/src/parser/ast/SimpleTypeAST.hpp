#ifndef __parser__ast__SimpleTypeAST
#define __parser__ast__SimpleTypeAST

#include "ASTNode.hpp"
#include "TypeAST.hpp"
#include "IdAST.hpp"

#include "lexer/tokens.hpp"

#include <deque>

namespace parser::ast {


  class SimpleTypeAST: public TypeAST {
    unique_ptr<IdAST> uuname;
  public:
    static unique_ptr<SimpleTypeAST> parse(deque<lexer::Token>& tokens);
  };





}

#endif