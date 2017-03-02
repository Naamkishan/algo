/**
 * Contains the required classes/structs and enums for representing and traversing the grid
 */

#ifndef ALGO_GRID_COMPONENTS_H
#define ALGO_GRID_COMPONENTS_H

#include <iterator>

namespace algo {

namespace problems {

/**
 * Coordinates
 */
struct Coordinates {
  int x_;
  int y_;
};

/**
 * Enum helpers
 */
template<typename T> using Underlying = typename std::underlying_type<T>::type;

template<typename T>
constexpr Underlying<T> underlying(T t) { return Underlying<T>(t); }

template <typename T>
struct TruthValue {
  T t_;
  constexpr TruthValue(T t) : t_(t) {}
  constexpr operator T() const { return t_; }
  constexpr explicit operator bool() const { return underlying(t_); }
};

/**
 * Allowed directions to traverse the grid
 */
enum AllowedDirections {
  NONE = 0,     // not set
  RIGHT = 1,
  LEFT = 2,
  UP = 4,
  DOWN = 8,
  DIAGONAL = 16,
  MAX_ALLOWED = LEFT | RIGHT | UP | DOWN | DIAGONAL
};

constexpr AllowedDirections operator|(AllowedDirections dir_1, AllowedDirections dir_2) {
  return static_cast<AllowedDirections>(underlying(dir_1) | underlying(dir_2));
}

constexpr AllowedDirections operator&(AllowedDirections dir_1, AllowedDirections dir_2) {
  return static_cast<AllowedDirections>(underlying(dir_1) & underlying(dir_2));
}

constexpr AllowedDirections operator~(AllowedDirections dir) {
  return static_cast<AllowedDirections>(~underlying(dir));
}

} // namespace algo::problems
} // namespace algo

#endif //ALGO_GRID_COMPONENTS_H
