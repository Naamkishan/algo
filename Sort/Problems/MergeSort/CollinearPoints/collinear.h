#ifndef ALGO_COLLINEAR_H
#define ALGO_COLLINEAR_H

#include <ostream>
#include <limits>

namespace algo {

namespace problems {

/**
 * @brief   The coordinates.
 */
struct Point {
  int x_;
  int y_;

  Point(int x = 0, int y = 0) : x_{x}, y_{y} {}
  Point(const Point& pt) : x_{pt.x_}, y_{pt.y_} {}

  /**
   * @brief     Determines the slope with *this* being the origin
   * @param other : the point with which slope is to be determined with
   * @return
   */
  double slope(const Point& other) const {
    double y_diff = other.y_ - y_;
    double x_diff = other.x_ - x_;

    if(x_diff == 0) {
      return (y_diff < 0) ? std::numeric_limits<double>::min() : std::numeric_limits<double>::max();
    }

    return y_diff/x_diff;
  }

  bool operator==(const Point& pt) const {
    if(pt.y_ == y_)
      return pt.x_ == x_;
    return false;
  }

  bool operator<(const Point& pt) const {
    if(pt.y_ == y_) {
      return x_ < pt.x_;
    }
    return y_ < pt.y_;
  }
};

/**
 * @brief   The line that connects two points
 */
struct LineSegment {
  Point to_;
  Point from_;

  LineSegment(const Point& pt1, const Point& pt2) {
    if(pt1 < pt2) {
      from_= pt1;
      to_ = pt2;
    } else {
      from_= pt2;
      to_ = pt1;
    }
  }

  double slope() const { return from_.slope(to_); }
  bool contains(const Point& pt) const {
    if((pt == to_) || (pt == from_))return true;
    return (to_.slope(pt) == slope()) && (from_.slope(pt) == slope());
  }

  void print(std::ostream& oss) const {
    oss << "From (" << from_.x_ << ", " << from_.y_ << ") => to (" << to_.x_ << " , " << to_.y_ << ") ";
  }


};


} // algo::problems

} // namespace algo

#endif //ALGO_COLLINEAR_H
