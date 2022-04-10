#include "TypeAST.hpp"

#include "errors.hpp"

#include "SimpleTypeAST.hpp"

namespace parser::ast {

  /**
   * @brief Factory function that creates a GlobDefAST
   * 
   * @param tokens 
   * @return unique_ptr<GlobDefAST> 
   */
  unique_ptr<TypeAST> TypeAST::parse(deque<lexer::Token>& tokens) {

    // if the type is a simple type
    if(tokens[0].type == lexer::TokenType::ID) {
      return SimpleTypeAST::parse(tokens);
    }

    cout << "MORE TO DO: " << "TypeAST" << endl;
    exit(1);

    return nullptr;
  }





}