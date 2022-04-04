#include "lexer.hpp"

namespace lexer {

  /**
   * @brief Tokenizes a program from standard input
   * 
   * @return deque<Token> 
   */
  deque<Token> lex(istream& in) {
    auto match_functions = get_match_functions();

    // init the deque
    deque<Token> tokens;

    // init loop state
    unsigned int line = 1;
    string current = "";
    Token last_valid_token = Token {
      .type = TokenType::_ERROR,
      .value = "",
      .line = line
    };
    char c;
    in.get(c);

    // iterate over every char in in
    while(in) {

      // append to current
      current += c;

      // if the token is whitespace, reset token and continue, incrementing line
      if(isspace(current[0])) {
        if(c == '\n') line++;
        current = current.substr(1);
        in.get(c);
        continue;
      }

      // if the token matches no keywords, pick the last valid token
      bool all_invalid = true;
      for(auto& match_function: match_functions) {
        if(match_function(current) != TokenType::_ERROR) {
          all_invalid = false;
          break;
        }
      }
      if(all_invalid) {

        // if there is no last token
        if(last_valid_token.type == TokenType::_ERROR) {
          error_unrecognized_token(current, line);
        }

        // push the new token and continue
        tokens.push_back(last_valid_token);
        last_valid_token = Token {
          .type = TokenType::_ERROR,
          .value = "",
          .line = line
        };
        current = "";
        continue;
      }

      // if a token matches any type
      for(auto& match_function: match_functions) {
        TokenType type = match_function(current);
        if(type != TokenType::_ERROR && type != TokenType::_PARTIAL) {
          
          // set last valid token
          last_valid_token = Token {
            .type = type,
            .value = current,
            .line = line
          };
          break;
        }
      }
      in.get(c);
    }

    // handle the last tokens
    if(last_valid_token.type == TokenType::_ERROR) {
      if(tokens.size() < 1) {
        error_unrecognized_token(current, line);
      }
    }  
    else {
      // push the new token and continue
      tokens.push_back(last_valid_token);
    }
    
    // return tokens
    return tokens;
  }

}