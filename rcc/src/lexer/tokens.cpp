#include "tokens.hpp"


namespace lexer {

  /**
   * @brief Determines the status of a token that is meant to be an SEMI
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType SEMI_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == SEMI) return TokenType::SEMI;
    return TokenType::_ERROR;
  }
  
  /**
   * @brief Determines the status of a token that is meant to be an LCARROT
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType LCARROT_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == LCARROT) return TokenType::LCARROT;
    return TokenType::_ERROR;
  }

  /** 
   * @brief Determines the status of a token that is meant to be an RCARROT
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType RCARROT_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == RCARROT) return TokenType::RCARROT;
    return TokenType::_ERROR;
  }


  /**
   * @brief Determines the status of a token that is meant to be the const
   * keyword
   * 
   * @param token 
   * @return TokenType 
   */
  TokenType KW_CONST_match(string token) {
    if(token == KW_CONST)
      return TokenType::KW_CONST;
    if (
      token.length() < KW_CONST.length() && 
      token == KW_CONST.substr(0, token.length())
    ) return TokenType::_PARTIAL;
    return TokenType::_ERROR;
  }

  /**
   * @brief 
   * 
   * @param token 
   * @return TokenType 
   */
  TokenType KW_DEF_match(string token) {
    if(token == KW_DEF)
      return TokenType::KW_DEF;
    if (
      token.length() < KW_DEF.length() && 
      token == KW_DEF.substr(0, token.length())
    ) return TokenType::_PARTIAL;
    return TokenType::_ERROR;
  }


  /**
   * @brief Determines the status of a token that is meant to be an DOT
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType DOT_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == DOT) return TokenType::DOT;
    return TokenType::_ERROR;
  }

  /**
   * @brief Determines the status of a token that is meant to be an ASSIGN
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType ASSIGN_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == ASSIGN) return TokenType::ASSIGN;
    return TokenType::_ERROR;
  }

  /**
   * @brief Determines the status of a token that is meant to be an ID
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType ID_match(string token) {

    // index of the token char
    unsigned int i = 0;

    // first alpha digit
    if(token.length() <= i) return TokenType::_PARTIAL;
    if(!isalpha(token[i])) return TokenType::_ERROR;
    i++;

    // make sure the rest are word characters
    for(; i < token.length(); i++) {
      if(!(isalnum(token[i]) || token[i] == '_')) {
        return TokenType::_ERROR;
      }
    }

    
    if(i < token.length()) return TokenType::_ERROR; // if the token isn't exhausted
    return TokenType::ID;
  }


  /**
   * @brief Determines the status of a token that is meant to be an NAT_LITERAL
   * 
   * @param token 
   * @return TokenType 
   */
  TokenType NAT_LITERAL_match(string token) {
  
    // index of the token char
    unsigned int i = 0;

    // first numeric digit
    if(i >= token.length()) return TokenType::_PARTIAL;
    if(!isdigit(token[i])) return TokenType::_ERROR;
    i++;

    // make sure the rest are numeric characters
    for(; i < token.length(); i++) {
      if(!(isdigit(token[i]) || token[i] == '_')) return TokenType::_ERROR;
    }

    // if successful, return FULL
    if(i < token.length()) return TokenType::_ERROR;
    return TokenType::NAT_LITERAL;
  }
}

