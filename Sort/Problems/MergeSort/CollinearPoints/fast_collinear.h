#ifndef ALGO_FASTCOLLINEAR_H
#define ALGO_FASTCOLLINEAR_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include <merge_sort.h>

#include "collinear.h"


namespace algo {

namespace problems {


class FastCollinear {
 public:

  using DistanceType = std::vector<LineSegment>::difference_type;

  FastCollinear(const std::vector<Point>& points, const std::size_t min_collinear_points = 4) :
      points_(points),
      min_collinear_points_{min_collinear_points} {
    init();
  }

  template<typename ForwardIterator>
  FastCollinear(ForwardIterator begin, ForwardIterator end,
                const std::size_t min_collinear_points = 4) :
      points_(begin, end),
      min_collinear_points_{min_collinear_points} {
    init();
  }


  void init() {
    get_line_segments();
  }

  DistanceType number_of_segments() const { return segments_.size(); }
  template<typename ForwardIterator>
  void segments(ForwardIterator segments) {
    std::copy(std::begin(segments_), std::end(segments_), segments);
  }

 private:

  /**
   * @brief Gets the total number of line segments and returns details of the line segments to the output parameter
   * @param             min_collinear_points : minimum number of collinear points inside a line segment (for a line segment to be qualified)
   * @return            the number of line segments
   */
  void get_line_segments() {
    // edge check. The number of points provided is less than the number required for a point to qualify as a collinear
    if(points_.size() >= min_collinear_points_) {

      auto pt_end = points_.end();
      std::advance(pt_end, -min_collinear_points_ + 1); // +1 >> must exclude the originating point of a collinear line

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

        // check for all possible collinear points for the current ref point : pt
        for (auto check_itr = std::next(itr); check_itr != points_.end();) {
          auto collinear_points = std::equal_range(check_itr,
                                                   points_.end(),
                                                   *check_itr,
                                                   [&pt](const Point &a, const Point &b) {
                                                     return pt.slope(a) < pt.slope(b);
                                                   });
          auto collinear_points_num = std::distance(collinear_points.first, collinear_points.second);

          if (collinear_points_num >= (min_collinear_points_ - 1)) {
            // since the points are all sorted now through merge sort ... the range of data points is now [itr], [collinear_points.first, collinear_points.second)
            auto minmax = std::minmax_element(collinear_points.first,
                                              collinear_points.second, // collinear_points (minmax needs to operate
                                              [](const Point &a, const Point &b) {
                                                if (a.y_ == b.y_)
                                                  return a.x_ < b.x_;
                                                return a.y_ < b.y_;
                                              });

            LineSegment line(std::min(*itr, *minmax.first), std::max(*itr, *minmax.second));
            // add the line to the existing list of line segments only iff it's not included by earlier runs
            auto line_itr = std::find_if(segments_.begin(),
                                         segments_.end(),
                                         [&line, &pt](const LineSegment &another) {
                                           return ((line.slope() == another.slope())
                                               && another.contains(pt)); // to take care of equal slopes of parallel lines
                                         });
            if (line_itr == std::end(segments_)) {
              segments_.push_back(line);
            }
          }

          // now skip the adjacent collinear points.. they all have been accounted for
          check_itr = std::next(check_itr,
                                collinear_points_num); // by default, there would be a minimum of 1 pair of collinear points
        }
      }
    }
  }

 private:
  const std::size_t         min_collinear_points_;
  std::vector<Point>        points_;
  std::vector<LineSegment>  segments_;

};

}

}

#endif //ALGO_FASTCOLLINEAR_H
