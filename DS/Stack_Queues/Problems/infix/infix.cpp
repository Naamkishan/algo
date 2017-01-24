#include <cstdlib>
#include <iostream>
#include <string>

#include "dijkstra_infix.h"

using namespace std;

int main() {
  std::cout << "Infix Expression Evaluation!" << std::endl;

  std::cout << "Evaluating (1 + ( ( 2 + 3 ) * ( 4  * 5 ) ) ): ";
  std::string expression("(1 +((2+3)*(4*5)))");

  std::cout << dijkstra_infix(expression);

  return EXIT_SUCCESS;
}