#include "errors.hpp"

/**
 * @brief Enum with all of the error types
 * 
 */
namespace ecode {
  enum ECode {
    unrecognized_token = 0,
    unrecognized_statement,
    unexpected_EOF,
    expected
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


/**
 * @brief Unexpected End of File error
 * 
 * @param line 
 */
void error_unexpected_EOF() {
  error(ecode::unexpected_EOF, -1);
  cout << "Unexpected EOF" << endl;
  exit(1);
}


/**
 * @brief Expected token but got error
 * 
 * @param expected 
 * @param line 
 * @param got 
 */
void error_expected(string expected, unsigned int line, string got) {
  error(ecode::expected, line);
  cout << "Expected '" << expected << "' but got '" << got << "'" << endl;
  exit(1);
}