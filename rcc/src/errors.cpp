#include "errors.hpp"

/**
 * @brief Enum with all of the error types
 * 
 */
namespace ecode {
  enum ECode {
    unrecognized_token = 0,
    unrecognized_statement
  };
}

/**
 * @brief 
 * 
 * @param error 
 * @return ostream 
 */
void error(ecode::ECode ecode, unsigned int line) {
  cout << "Error " << ecode << " Line " << line << ": ";
};

/**
 * @brief Unrecognized token error
 * 
 * @param token 
 */
void error_unrecognized_token(string token, unsigned int line) {
  error(ecode::unrecognized_token, line);
  cout << "Unrecognized token: '" << token << "'" << endl;
  exit(1);
}

/**
 * @brief Unrecognized token error
 * 
 * Reached when the compiler hits a statement that starts with an invalid token
 * 
 * @param token 
 * @param line 
 */
void error_unrecognized_statement(string token, unsigned int line) {
  error(ecode::unrecognized_statement, line);
  cout << "Statement can't begin with token: '" << token << "'" << endl;
  exit(1);
}