
#include "GlobDefAST.hpp"

namespace parser::ast {


  /**
   * @brief Factory function that creates a GlobDefAST
   * 
   * @param tokens 
   * @return unique_ptr<GlobDefAST> 
   */
  unique_ptr<GlobDefAST> GlobDefAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<GlobDefAST>();

    

    return self;
  }
}