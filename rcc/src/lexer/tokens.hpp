#ifndef __lexer_tokens
#define __lexer_tokens

#include <iostream>
#include <vector>
#include <map>

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
    RES,
    LCARROT,
    RCARROT,

    // key words
    KW_DEF,
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
  static string RES = "::";
  static string LCARROT = "<";
  static string RCARROT = ">";
  static string KW_CONST = "const";
  static string KW_DEF = "def";
  static string DOT = ".";
  static string ASSIGN = "=";


  // keyword vector (to proper ordering)
  static vector<TokenType> keywords = {
    TokenType::SEMI,
    TokenType::RES,
    TokenType::LCARROT,
    TokenType::RCARROT,
    TokenType::KW_CONST,
    TokenType::KW_DEF,
    TokenType::DOT,
    TokenType::ASSIGN
  };


  // keyword map
  static map<TokenType, string> keyword_map = {
    {TokenType::SEMI, SEMI},
    {TokenType::RES, RES},
    {TokenType::LCARROT, LCARROT},
    {TokenType::RCARROT, RCARROT},
    {TokenType::KW_CONST, KW_CONST},
    {TokenType::KW_DEF, KW_DEF},
    {TokenType::DOT, DOT},
    {TokenType::ASSIGN, ASSIGN},
  };



  // match functions
  TokenType ID_match(string token);
  TokenType NAT_LITERAL_match(string token);

  // match_functions vector
  vector<function<TokenType(string)>> get_match_functions();
}
#endif