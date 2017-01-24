#ifndef ALGO_DIJKSTRA_INFIX_H
#define ALGO_DIJKSTRA_INFIX_H

#include <string>
#include <cstdlib>
#include "Stack.h"

/**
 * Dijkstra's Two Stack infix expression evaluation
 *
 * (1 + ( ( 2 + 3 ) * ( 4  * 5 ) ) )
 */
auto dijkstra_infix(const std::string& expression) {
  Stack<int> values;
  Stack<char> operators;

  auto result = 0.0;

  auto is_operator = [](char op) -> bool {
    switch (op) { case '+': case '-': case '*': case '/': return true; };
    return false;
  };

  auto evaluate = [](auto val1, auto val2, char op) {
    switch (op) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;
    };

    throw std::runtime_error("operator unsupported!");
  };

  for(char value: expression) {
    if(std::isdigit(value)) {
      values.push(std::atoi(&value));
    } else if(is_operator(value)) {
      operators.push(value);
    } else {
      if(value == ')') {
        values.push(evaluate(values.pop(), values.pop(), operators.pop()));
      }
    }
  }

  return values.pop();
}

#endif //ALGO_DIJKSTRA_INFIX_H
