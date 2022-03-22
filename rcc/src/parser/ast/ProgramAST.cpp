#include "ProgramAST.hpp"

namespace parser::ast {

  /**
   * @brief Factory that constructs and ProgramAST object
   * 
   * @param tokens 
   */
  unique_ptr<ProgramAST> ProgramAST::parse(deque<lexer::Token>& tokens) {
    auto self = make_unique<ProgramAST>();

    // while the decque remains full, get statements
    while(!tokens.empty()) {
      self->statements.push_back(StatementAST::parse(tokens));
    }

    return self;
  }
}