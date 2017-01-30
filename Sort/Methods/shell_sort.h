#ifndef ALGO_SHELL_SORT_H
#define ALGO_SHELL_SORT_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   Shell Sort -> stl container complaint. Using Knuth formula: gap = 3h + 1
 *
 * @param begin         Start of range
 * @param end           End of range
 * @param comparator    comparator function which defaults to std::less
 */
template<typename Iterator,
    typename Comparator = std::less<
        typename std::iterator_traits<Iterator>::value_type>
>
void shell_sort(Iterator begin, Iterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<Iterator>::difference_type;

  DistanceType gap = {1};
  DistanceType length = std::distance(begin, end);

  while (gap < length / 3) gap = 3 * gap + 1;

  while (gap >= 1) {
    auto first = begin;
    std::advance(first, gap);
    for (; first != end; std::advance(first, 1)) {
      auto itr = first;
      auto pivot = *itr;
      while ((std::distance(begin, itr) >= gap) && comparator(pivot, *std::next(itr, -gap))) {
        *itr = *std::next(itr, -gap);
        std::advance(itr, -gap);
      }
      *itr = pivot;
    }

    gap /= 3;
  }

}

} // namespace algo::sort

} // namespace algo

#endif //ALGO_SHELL_SORT_H
