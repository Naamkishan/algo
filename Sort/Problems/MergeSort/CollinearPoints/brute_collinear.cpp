#include "brute_collinear.h"

#include <algorithm>
#include <map>

namespace algo {

namespace problems {

/**
 * @brief   This finds line segments (containing at least 4 collinear points).
 *          The line segment may also contain more than 4 collinear points
 *
 * @param line_segments : the output parameter that would contain the number of line segments found
 * @return
 */
std::size_t BruteCollinear::get_line_segments(std::vector<LineSegment> *line_segments) {
  std::vector<LineSegment>& lines = *line_segments;

  for(auto first = std::begin(points_); first != std::end(points_); ++first) {
    Point pt_first = *first;
    for(auto second = std::next(first); second != std::end(points_); ++second) {
      Point pt_second = *second;
      double slope = pt_first.slope(pt_second);

      for(auto third = std::next(second); third != std::end(points_); ++third) {
        if(pt_first.slope(*third) == slope) {
          for(auto fourth = std::next(third); fourth != std::end(points_); ++fourth) {
            if(pt_first.slope(*fourth) == slope) {
              LineSegment line_segment(pt_first, *fourth);

              // look up to see if its already present or not
              auto lines_itr = std::find_if(lines.begin(),
                                            lines.end(),
                                            [&line_segment](const LineSegment ls) { // the comparator lambda
                                              return line_segment.slope() == ls.slope();
                                            });
              if(lines_itr == lines.end()) {
                lines.push_back(line_segment);
              } else {
                if(*fourth < (*lines_itr).from_)
                  (*lines_itr).from_ = *fourth;
                else if((*lines_itr).to_ < *fourth)
                  (*lines_itr).to_ = *fourth;
              }

            }
          }
        }
      }
    }
  }

  return lines.size();
}

}

}
