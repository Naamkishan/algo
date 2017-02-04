#ifndef ALGO_AUTOLOAN_H
#define ALGO_AUTOLOAN_H

#include <cmath>
#include <exception>

namespace SortEstimate {

bool is_essentially_equal(const double& a, const double& b, const double& tolerance = 1e-9) {
  return (std::fabs(a - b) <= tolerance);
}


double how_many(int c, int time) {
  throw std::logic_error("Function not implemented!");
}

} // namespace SortEstimate

#endif //ALGO_AUTOLOAN_H
