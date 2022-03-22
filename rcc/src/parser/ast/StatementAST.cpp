#include "StatementAST.hpp"

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
    if(tokens.size() > 2 && tokens[0].type == lexer::TokenType::ID && tokens[1].type == lexer::TokenType::ID) {
      return GlobDefAST::parse(tokens);
    }

    
  }
}