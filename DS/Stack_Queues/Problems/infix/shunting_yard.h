#ifndef ALGO_DIJKSTRA_INFIX_H
#define ALGO_DIJKSTRA_INFIX_H

#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Stack.h"

namespace {

bool is_operator(const std::string& op) {
  return ((op == "-") || (op == "+") ||
      (op == "*") || (op == "/") || (op == "%") ||
      (op == "^") ||
      (op == "}") || (op == "]")) ||
      (op == "{") || (op == "[") ||
      (op == "(") || (op == ")");
}


double evaluate(double val1, double val2, const std::string& op) {
  if(op == "+") return (val1 + val2);
  if(op == "-") return (val1 - val2);
  if(op == "*") return val1 * val2;
  if(op == "/") return (val1 / val2);
  if(op == "^") return std::pow(val1, val2);

  throw std::runtime_error("operator unsupported!");
}


/**
 * @brief       priority gives operator priority number.
 * @details     Opening brackets always end with hexa 01 while closing with hexa 10 to speed up comparisons.
 * @param       op
 * @return      int but throws exception if op passed is not handled
 */
int priority(const std::string& op) {
  if(op == "^") return 0x0400;
  if(op == ")") return 0x0310;
  if(op == "(") return 0x0301;
  if(op == "}") return 0x0210;
  if(op == "{") return 0x0201;
  if(op == "]") return 0x0110;
  if(op == "[") return 0x0101;
  if((op == "*") || (op == "/") || (op == "%"))
    return 0x0004;
  if((op == "+") || (op == "-"))
    return 0x0002;
  if(op == "=")
    return 0x0000;

  throw std::runtime_error("operator unsupported!");
}

/**
 * @brief       checks if operator is opening bracket (priority value must end with 0x0005)
 * @param       operator symbol
 * @return      boolean
 */
inline bool opening_bracket(const std::string &op) {
  return (priority(op) & 0x0001);
}

inline bool closing_bracket(const std::string &op) {
  return (priority(op) & 0x0010);
}


inline bool lower_priority(const std::string& op1, const std::string& op2) {
  return (priority(op1) < priority(op2));
}

/**
 * @brief       Provide the corresponding opening bracket symbol for a given closing bracket symbol
 * @param       closing_bracket
 * @return      const char*
 */
const char* matching_brackets(const std::string& closing_bracket) {
  if(closing_bracket == ")")  return "(";
  if(closing_bracket == "}")  return "{";
  if(closing_bracket == "]")  return "[";

  throw std::runtime_error("unsupported bracket!");
}

/**
 * @brief                   Processes the entire expression contained inside the brackets () or {} or []. The result is pushed onto the stack
 * @param values            The values(numbers) stack
 * @param operators         The operands stack
 * @param close_bracket   The bracket that has to be evaluated. e.g., () or {} or []
 */
void evaluate_bracket(Stack<double>* values, Stack<std::string>* operators, const std::string& close_bracket) {
  const std::string open_bracket = matching_brackets(close_bracket);

  for(std::string operand = operators->pop(); operand != open_bracket; operand = operators->pop()) {
    // brackets can have nested brackets
    if(closing_bracket(operand)) {
      evaluate_bracket(values, operators, operand);
    }
    values->push(evaluate(values->pop(), values->pop(), operand));
  }
}

}

/**
 * Dijkstra's Two Stack infix expression evaluation
 * Shunting Yard Algorithm
 */
auto dijkstra_infix(const std::string& expression) {
  Stack<double> values;
  Stack<std::string> operators;

  std::stringstream ss;
  ss << "( " << expression << " )";

  std::string token;
  std::string prev_op;

  while(ss >> token) {
    if(is_operator(token)) {
      if(opening_bracket(token)) {
        operators.push(token);
      } else {
        prev_op = operators.pop();
        if (closing_bracket(token)) {
          operators.push(prev_op);
          evaluate_bracket(&values, &operators, token);
        } else {
          if (!opening_bracket(prev_op) && lower_priority(token, prev_op)) {
            values.push(evaluate(values.pop(), values.pop(), prev_op));
          } else {
            operators.push(prev_op);
          }
          operators.push(token);
        }
      }
    } else {
      values.push(std::stod(token));
    }
  }

  return values.pop();
}

#endif //ALGO_DIJKSTRA_INFIX_H
