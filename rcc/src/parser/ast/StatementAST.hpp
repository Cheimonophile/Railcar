#ifndef __parser__ast__StatementAST
#define __parser__ast__StatementAST

#include <iostream>
#include <deque>
#include <memory>

#include "lexer/tokens.hpp"

#include "ASTNode.hpp"

using namespace std;

namespace parser::ast {

  class StatementAST: public ASTNode {
  public:
    static unique_ptr<StatementAST> parse(deque<lexer::Token>& tokens);
  };
}


#endif