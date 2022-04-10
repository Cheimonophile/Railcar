#ifndef __parser__ast__GlobDefAST
#define __parser__ast__GlobDefAST

#include <iostream>
#include <memory>

#include "ASTNode.hpp"
#include "StatementAST.hpp"
#include "TypeAST.hpp"
#include "LiteralAST.hpp"

using namespace std;

namespace parser::ast {

  class GlobDefAST: public StatementAST {
    lexer::Token def;
    unique_ptr<TypeAST> type;
    lexer::Token name;
    unique_ptr<LiteralAST> value;
  public:
    static unique_ptr<GlobDefAST> parse(deque<lexer::Token>& tokens);
  };

}



#endif