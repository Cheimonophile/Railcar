#include "LiteralAST.hpp"


namespace parser::ast {
  
  unique_ptr<LiteralAST> LiteralAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<LiteralAST>();
    

    return self;
  }



}