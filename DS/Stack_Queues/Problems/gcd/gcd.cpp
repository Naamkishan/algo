#include <iostream>

template<typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  std::cout << "Greatest Common Denominator!" << std::endl;

  auto num1 = 24;
  auto num2 = 18;

  std::cout << "GCD for " << num1 << ", " << num2 << ": " << gcd(num1, num2) << std::endl;

  return 0;
}