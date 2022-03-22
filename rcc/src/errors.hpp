#ifndef __errors
#define __errors

#include <iostream>

#include "lexer/lexer.hpp"

using namespace std;



void error_unrecognized_token(string token, unsigned int line);
void error_unrecognized_statement(string token, unsigned int line);

#endif