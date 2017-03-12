#ifndef ALGO_BRUTE_COLLINEAR_H
#define ALGO_BRUTE_COLLINEAR_H

#include <vector>

#include "collinear.h"

namespace algo {

namespace problems {

/**
 * This can calculate a number of line segments that takes 4 collinear points
 */
class BruteCollinear {
 public:
  BruteCollinear(const std::vector<Point>& points) : points_(points) {}

  /**
   * @brief gets the number of line segments that contains 4 collinear points
   * @param line_segments
   * @return
   */
  std::size_t get_line_segments(std::vector<LineSegment>* line_segments);

 private:
  std::vector<Point>    points_;
};


} // algo::problems

} // namespace algo


#endif //ALGO_BRUTE_COLLINEAR_H
