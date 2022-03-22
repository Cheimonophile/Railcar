#ifndef __lexer_lexer
#define __lexer_lexer

#include <iostream>
#include <deque>
#include <fstream>

#include "tokens.hpp"

using namespace std;

namespace lexer {


  deque<Token> lex(ifstream& in);
  void unrecognized_token(string token);


}
#endif