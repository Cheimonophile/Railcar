#include "tokens.hpp"


namespace lexer {

  

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
    if(
      token.length() < KW_CONST.length() && 
      token == KW_CONST.substr(0, token.length())
    )
      return TokenType::_PARTIAL;
    return TokenType::_ERROR;
  }


  /**
   * @brief Determines the status of a token that is meant to be an PERIOD
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType PERIOD_match(string token) {
    if(token.length() < 1) return TokenType::_PARTIAL;
    if(token == PERIOD) return TokenType::PERIOD;
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
   * @brief Determines the status of a token that is meant to be an ID
   * 
   * @param status 
   * @return TokenType 
   */
  TokenType ID_match(string token) {

    // index of the token char
    unsigned int i = 0;

    // first alphanumeric digit
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

    // first alphanumeric digit
    if(i >= token.length()) return TokenType::_PARTIAL;
    if(!isdigit(token[i])) return TokenType::_ERROR;
    i++;

    // make sure the rest are word characters
    for(; i < token.length(); i++) {
      if(!isdigit(token[i])) return TokenType::_ERROR;
    }

    // if successful, return FULL
    if(i < token.length()) return TokenType::_ERROR;
    return TokenType::NAT_LITERAL;
  }
}

