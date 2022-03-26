#include "main.hpp"

#include "parser/ast/ProgramAST.hpp"

#include "lexer/tokens.hpp"




int main(int argc, char** argv) {


  // make sure file path included
  if(argc < 1) {
    print_usage();
  }

  auto three = test::TestEnum::One;
  auto four = test::TestEnum::Two;

  if(three == four) {
    cout << "Different" << endl;
  }
  else {
    cout << "same" << endl;
  }

  auto one = lexer::TokenType::KW_DEF;
  auto two = lexer::TokenType::KW_CONST;

  if(one == two) {
    cout << "different" << endl;
    //return GlobDefAST::parse(tokens);
  }
    

  // open the file stream
  ifstream file;
  file.open(argv[1], ifstream::in);

  // lex fron stdin
  auto tokens = lexer::lex(file);

  // print the tokens
  for(auto& token: tokens) {
    cout << token.line << ":\t" << token.value <<  endl;
  }

  // parse the tokens
  auto ast = parser::ast::ProgramAST::parse(tokens);

  cout << "Done!\n";

  return 0;
}