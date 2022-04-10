
#include "GlobDefAST.hpp"

#include "errors.hpp"
#include "lexer/tokens.hpp"

namespace parser::ast {


  /**
   * @brief Factory function that creates a GlobDefAST
   * 
   * @param tokens 
   * @return unique_ptr<GlobDefAST> 
   */
  unique_ptr<GlobDefAST> GlobDefAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<GlobDefAST>();

    // KW_DEF
    if(tokens.empty()) error_unexpected_EOF();
    if(tokens[0].type != lexer::TokenType::KW_DEF) {
      error_expected(lexer::KW_DEF, tokens[0].line, tokens[0].value);
    } 
    self->def = tokens[0];
    tokens.pop_front();

    // type
    self->type = TypeAST::parse(tokens);

    // ID
    if(tokens.empty()) error_unexpected_EOF();
    if(tokens[0].type != lexer::TokenType::ID) {
      error_expected("<identifier>", tokens[0].line, tokens[0].value);
    }
    self->id = tokens[0];
    tokens.pop_front();

    // expression



    cout << "MORE TO DO: " << "GlobDefAST" << endl;
    exit(1);

    return self;
  }
}