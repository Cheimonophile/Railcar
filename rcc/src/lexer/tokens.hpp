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

    // utility
    _ERROR,
    _PARTIAL,

    // punctuation
    SEMI,
    LCARROT,
    RCARROT,

    // key words
    KW_CONST,

    // operators
    DOT,
    ASSIGN,

    // names
    ID,

    // literals
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
  static string SEMI = ";";
  static string LCARROT = "<";
  static string RCARROT = ">";
  static string KW_CONST = "const";
  static string DOT = ".";
  static string ASSIGN = "=";

  // partial tokens
  TokenType SEMI_match(string token);
  TokenType KW_CONST_match(string token);
  TokenType DOT_match(string token);
  TokenType ASSIGN_match(string token);
  TokenType LCARROT_match(string token);
  TokenType RCARROT_match(string token);
  TokenType ID_match(string token);
  TokenType NAT_LITERAL_match(string token);

  // match_functions vector
  static vector<TokenType(*)(string)> match_functions = {
    SEMI_match,
    LCARROT_match,
    RCARROT_match,
    KW_CONST_match,
    DOT_match,
    ASSIGN_match,
    ID_match,
    NAT_LITERAL_match
  };
}
#endif