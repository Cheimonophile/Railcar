#include "TypeAST.hpp"

#include "errors.hpp"

namespace parser::ast {

  /**
   * @brief Factory function that creates a GlobDefAST
   * 
   * @param tokens 
   * @return unique_ptr<GlobDefAST> 
   */
  unique_ptr<TypeAST> TypeAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<TypeAST>();

    cout << "MORE TO DO: " << "TypeAST" << endl;
    exit(1);

    return self;
  }





}