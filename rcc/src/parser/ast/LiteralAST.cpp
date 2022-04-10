#include "LiteralAST.hpp"

#include "NatLiteralAST.hpp"


namespace parser::ast {
  
  unique_ptr<LiteralAST> LiteralAST::parse(deque<lexer::Token>& tokens) {

    // make sure more tokens exist
    if(tokens.empty()) error_unexpected_EOF();

    // nat literal
    if(tokens[0].type == lexer::TokenType::NAT_LITERAL) {
      return NatLiteralAST::parse(tokens);
    }
    
    


    cout << "MORE TO DO: " << "LiteralAST" << endl;
    exit(1);

    return nullptr;
  }



}