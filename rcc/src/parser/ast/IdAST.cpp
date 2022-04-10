#include "IdAST.hpp"

#include "errors.hpp"

namespace parser::ast {

  /**
   * @brief Factory function that creates a GlobDefAST
   * 
   * @param tokens 
   * @return unique_ptr<GlobDefAST> 
   */
  unique_ptr<IdAST> IdAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<IdAST>();


    // IDs
    while(true) {

      // ID
      if(tokens.empty()) error_unexpected_EOF();
      if(tokens[0].type != lexer::TokenType::ID) {
        error_expected("<identifier>", tokens[0].line, tokens[0].value);
      }
      self->ids.push_back(tokens[0]);
      tokens.pop_front();

      // RES
      if(tokens.empty()) error_unexpected_EOF();
      if(tokens[0].type != lexer::TokenType::RES) break;
      tokens.pop_front();
    }

    return self;
  }





}