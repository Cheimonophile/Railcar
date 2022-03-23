#include "StatementAST.hpp"

#include "errors.hpp"

#include "GlobDefAST.hpp"


namespace parser::ast {

  /**
   * @brief Factory that constructs a StatementAST
   * 
   * @param tokens 
   * @return unique_ptr<StatementAST> 
   */
  unique_ptr<StatementAST> StatementAST::parse(deque<lexer::Token>& tokens) {

    // if the statement is a global definition
    if(tokens.empty()) error_unexpected_EOF();
    auto token = tokens[0];
    auto one = lexer::TokenType::KW_DEF;
    auto two = lexer::TokenType::KW_CONST;

    if(one == two) {
      return GlobDefAST::parse(tokens);
    }

    // if(tokens[0].type == lexer::TokenType::KW_DEF) {
    //   return GlobDefAST::parse(tokens);
    // }

    
  }
}