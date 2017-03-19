#ifndef ALGO_UTILITY_H
#define ALGO_UTILITY_H

#include <algorithm>
#include <random>

namespace Utility {

bool is_essentially_equal(const double& a, const double& b, const double& tolerance = 1e-9) {
  return (std::fabs(a - b) <= tolerance);
}

template<typename ForwardIterator>
void shuffle(ForwardIterator begin, ForwardIterator end) {
  // randomise
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(begin, end, gen);
}

}

#endif //ALGO_UTILITY_H
