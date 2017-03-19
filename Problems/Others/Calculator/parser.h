#ifndef ALGO_INFIX_CALC_H
#define ALGO_INFIX_CALC_H

#include <string>

/**
 * The grammer for the calculator parser
 *
 * infix_calc:
 *      end                 // end of input
 *      expr_list end
 * expr_list:
 *      expression print    // print is newline or semicolon
 *      expression print expr_list
 *
 * expression:
 *      expression + term
 *      expression - term
 *      term
 *
 * term:
 *      term / primary
 *      term * primary
 *      primary
 *
 * primary:
 *      number                  // floating point literal
 *      name                    // name is an identifier
 *      name = expression
 *      -primary
 *      (expression)
 */

namespace algo {
namespace problems {

/**
 * @brief Kind : Definition of Token's kind (nature)
 */
enum class Kind : char {
  name, number, end,
  plus = '+', minus = '-', mul = '*', div = '/',
  print = ';', assign = '=', lp = '(', rp = ')'
};

/**
 * @brief Token : definition of tokens to be used by the calculator
 */
struct Token {
  Kind          kind_;
  std::string   str_value;
  double        num_value;
};

class TokenStream {
 public:
  Token get();            // read and return the next token
  const Token& current(); // most recently read token
};

} // namespace algo::problems
} // namespace algo

#endif //ALGO_INFIX_CALC_H
