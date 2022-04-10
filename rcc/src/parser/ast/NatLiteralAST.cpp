#include "NatLiteralAST.hpp"


namespace parser::ast {
  
  unique_ptr<NatLiteralAST> NatLiteralAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<NatLiteralAST>();
    
    // value
    if(tokens.empty()) error_unexpected_EOF();
    if(tokens[0].type != lexer::TokenType::NAT_LITERAL) {
      error_expected("<literal natural>", tokens[0].line, tokens[0].value);
    }
    self->value = tokens[0];
    tokens.pop_front();

    return nullptr;
  }



}