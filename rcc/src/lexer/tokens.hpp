#ifndef __lexer_tokens
#define __lexer_tokens

#include <iostream>
#include <vector>

using namespace std;

namespace lexer {

  /**
   * @brief Enum representing the type of the token
   * 
   */
  enum class TokenType {
    _ERROR,
    _PARTIAL,
    KW_CONST,
    PERIOD,
    ASSIGN,
    LCARROT,
    RCARROT,
    ID,
    NAT_LITERAL
  };


  /**
   * @brief Struct representing a token
   * 
   */
  typedef struct {
    TokenType type;
    string value;
    unsigned int line;
  } Token;


  // static tokens
  static string KW_CONST = "const";
  static string PERIOD = ".";
  static string ASSIGN = "=";
  static string LCARROT = "<";
  static string RCARROT = ">";

  // partial tokens
  TokenType KW_CONST_match(string token);
  TokenType PERIOD_match(string token);
  TokenType ASSIGN_match(string token);
  TokenType LCARROT_match(string token);
  TokenType RCARROT_match(string token);
  TokenType ID_match(string token);
  TokenType NAT_LITERAL_match(string token);

  // match_functions vector
  static vector<TokenType(*)(string)> match_functions = {
    KW_CONST_match,
    PERIOD_match,
    ASSIGN_match,
    LCARROT_match,
    RCARROT_match,
    ID_match,
    NAT_LITERAL_match
  };
}
#endif