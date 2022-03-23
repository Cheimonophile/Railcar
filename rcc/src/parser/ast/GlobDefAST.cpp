
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
    if(tokens.size() < 1) error_unexpected_EOF();
    auto token = tokens[0];
    if(tokens[0].type != lexer::TokenType::KW_DEF) error_expected(lexer::KW_DEF, tokens[0].line, tokens[0].value);
    self->def = tokens[0];
    tokens.pop_front();

    return self;
  }
}