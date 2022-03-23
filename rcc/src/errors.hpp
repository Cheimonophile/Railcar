#ifndef __errors
#define __errors

#include <iostream>

#include "lexer/lexer.hpp"

using namespace std;



void error_unrecognized_token(string token, unsigned int line);
void error_unrecognized_statement(string token, unsigned int line);
void error_unexpected_EOF();
void error_expected(string expected, unsigned int line, string got);

#endif