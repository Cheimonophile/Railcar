#ifndef __parser__ast__ProgramAST
#define __parser__ast__ProgramAST

#include <iostream>
#include <deque>
#include <memory>

#include "lexer/tokens.hpp"

#include "ASTNode.hpp"
#include "StatementAST.hpp"

using namespace std;

namespace parser::ast {

  class ProgramAST: public ASTNode {
    vector<unique_ptr<StatementAST>> statements;
  public:
    static unique_ptr<ProgramAST> parse(deque<lexer::Token>& tokens);
  };
}


#endif