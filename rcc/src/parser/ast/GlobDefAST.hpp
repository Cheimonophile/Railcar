#ifndef __parser__ast__GlobDefAST
#define __parser__ast__GlobDefAST

#include <iostream>
#include <memory>

#include "ASTNode.hpp"
#include "StatementAST.hpp"

using namespace std;

namespace parser::ast {

  class GlobDefAST: public StatementAST {
    lexer::Token def;
    lexer::Token name;
    
  public:
    static unique_ptr<GlobDefAST> parse(deque<lexer::Token>& tokens);
  };

}



#endif