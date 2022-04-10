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

    cout << "MORE TO DO: " << "IdAST" << endl;
    exit(1);

    return self;
  }





}