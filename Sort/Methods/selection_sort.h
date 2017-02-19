#ifndef ALGO_SELECTION_SORT_H
#define ALGO_SELECTION_SORT_H

#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "quick_sort.h"

namespace algo {

namespace sort {

/**
 * @brief           used by selection to get the sort an "n" th element.
 *
 * @tparam  RandomIter      :   Random Iterator
 * @tparam Comparator       :   Compartor functor. Defaults to std::less
 *
 * @param begin     : start range
 * @param end       : end range
 * @param pos       : the "n"-th element - position on which the element is to be sorted {0 based index}
 * @return          : value of the sorted "n"th element
 */
template<typename RandomIter,
  typename Comparator = std::less<
    typename std::iterator_traits<RandomIter>::value_type>
>
auto select(RandomIter begin, RandomIter end,
            typename std::iterator_traits<RandomIter>::difference_type pos,
            Comparator comparator = Comparator()) {
  if((begin == end) || (pos > std::distance(begin, end))) {
    throw std::runtime_error("Out of range exception!");
  }

  // only a list having more than one element needs to be sorted
  if(std::distance(begin, end) > 1) {
    auto low = begin;
    auto high = end;
    typename std::iterator_traits<RandomIter>::difference_type cur_pos;

    while (high != low) {
      auto part_itr = partition_container(low, high, comparator);
      cur_pos = std::distance(begin, part_itr);
      if (cur_pos > pos) {
        high = std::next(part_itr, -1);
      } else if (cur_pos < pos) {
        low = std::next(part_itr, 1);
      } else {
        return *std::next(begin, cur_pos);
      }
    }
  }

  return *std::next(begin, pos);
}


template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type>
>
void selection_sort(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {
  if(begin != end) {
    for(auto itr = begin; itr != end; std::advance(itr, 1))  {
      select(begin, end, std::distance(begin, itr), comparator);
    }
  }
}

} // namespace algo::sort

// selection sort using standard library apis
namespace using_std {

template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type>
>
void selection_sort(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {
  if(begin != end) {
    for(auto itr = begin; itr != end; std::advance(itr, 1)) {
      std::nth_element(begin, itr, end, comparator);
    }
  }
}

} // namespace algo::using_std

} // namespace algo

#endif //ALGO_SELECTION_SORT_H
