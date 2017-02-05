#ifndef ALGO_UTILITY_H
#define ALGO_UTILITY_H

namespace Utility {

bool is_essentially_equal(const double& a, const double& b, const double& tolerance = 1e-9) {
  return (std::fabs(a - b) <= tolerance);
}

}

#endif //ALGO_UTILITY_H
