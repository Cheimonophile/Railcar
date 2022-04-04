#include "tokens.hpp"


namespace lexer {



  /**
   * @brief Initializes the token match functions
   * 
   */
  vector<function<TokenType(string)>> get_match_functions() {

    // init the static match functions vector
    static vector<std::function<TokenType(string)>> match_functions;

    // return if it already exists
    static atomic<bool> match_functions_initialized = false;
    if(match_functions_initialized) return match_functions;
    match_functions_initialized = true;

    // initialize single
    for(auto keyword: keywords) {

      // if the token is only one char in length
      if(keyword_map[keyword].length() == 1) {
        match_functions.push_back([keyword](string token) {
          if(token.length() < 1) return TokenType::_PARTIAL;
          if(token == keyword_map[keyword]) return keyword;
          return TokenType::_ERROR;
        });
      }

      // if the token is multiple chars in length
      else if(keyword_map[keyword].length() > 1) {
        match_functions.push_back([keyword](string token) {
          if(token == keyword_map[keyword])
            return keyword;
          if (
            token.length() < keyword_map[keyword].length() && 
            token == keyword_map[keyword].substr(0, token.length())
          ) return TokenType::_PARTIAL;
          return TokenType::_ERROR;
        });
      }

    }

    // fill in complex match functions
    match_functions.push_back(NAT_LITERAL_match);
    match_functions.push_back(ID_match);

    return match_functions;
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

