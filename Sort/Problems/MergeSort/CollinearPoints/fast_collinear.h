#ifndef ALGO_FASTCOLLINEAR_H
#define ALGO_FASTCOLLINEAR_H

#include <algorithm>
#include <iterator>
#include <vector>

#include <merge_sort.h>

#include "collinear.h"


namespace algo {

namespace problems {


class FastCollinear {
 public:
  FastCollinear(const std::vector<Point>& points) : points_(points) {}

  template<typename ForwardIterator>
  FastCollinear(ForwardIterator begin, ForwardIterator end) : points_(begin, end) {}

  /**
   * @brief Gets the total number of line segments and returns details of the line segments to the output parameter
   * @param[out]        line_segment : the caller must ensure that there's enough memory allocated
   * @param             min_collinear_points : minimum number of collinear points inside a line segment (for a line segment to be qualified)
   * @return            the number of line segments
   */
  template <typename ForwardIterator>
  typename std::iterator_traits<ForwardIterator>::difference_type
   get_line_segments(ForwardIterator line_segment, const std::size_t min_collinear_points = 4) {
    ForwardIterator segment_itr{line_segment};
    // edge check. The number of points provided is less than the number required for a point to qualify as a collinear
    if(points_.size() >= min_collinear_points) {

      auto pt_end = points_.end();
      std::advance(pt_end, -min_collinear_points + 1); // +1 >> must exclude the originating point of a collinear line

      for (auto itr = points_.begin(); itr != pt_end; ++itr) {
        // sort all lines drawn from this point with slope as sorting criteria
        const Point &pt = *itr;
        auto slope_comp = [&pt](const Point &first, const Point &second) {
          return (pt.slope(first) < pt.slope(second));
        };

        // partition the array such that all data points (with pt) falls to the left of the partition
        algo::sort::merge_sort(std::next(itr),
                               points_.end(),
                               [&pt](const Point &a, const Point &b) {

                                 return pt.slope(a) < pt.slope(b);
                               });

        // check for all possible collinear points for the current ref_pt
        for (auto check_itr = std::next(itr); check_itr != points_.end();) {
          auto collinear_points = std::equal_range(check_itr,
                                                   points_.end(),
                                                   *check_itr,
                                                   [&pt](const Point &a, const Point &b) {
                                                     return pt.slope(a) < pt.slope(b);
                                                   });
          auto collinear_points_num = std::distance(collinear_points.first, collinear_points.second);

          if (collinear_points_num >= (min_collinear_points - 1)) {
            // since the points are all sorted now through merge sort ... the range of data points is now [itr, collinear_points.second)
            auto minmax = std::minmax_element(itr, collinear_points.second, [](const Point &a, const Point &b) {
              if (a.y_ == b.y_)
                return a.x_ < b.x_;
              return a.y_ < b.y_;
            });

            LineSegment line(*minmax.first, *minmax.second);
            // add the line to the existing list of line segments only iff it's not included by earlier runs
            if (segment_itr == std::find_if(
                line_segment, segment_itr,
                [&line](const LineSegment &another) {
                  return line.slope() == another.slope();
                })) {
              *segment_itr = line;
              ++segment_itr;
            }
          }

          // now skip the adjacent collinear points.. they all have been accounted for
          check_itr = std::next(check_itr,
                                collinear_points_num); // by default, there would be a minimum of 1 pair of collinear points
        }
      }
    }
    return std::distance(line_segment, segment_itr);
  }

 private:
  std::vector<Point>  points_;

};

}

}

#endif //ALGO_FASTCOLLINEAR_H
