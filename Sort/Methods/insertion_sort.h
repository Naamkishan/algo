#ifndef ALGO_INSERTION_SORT_H
#define ALGO_INSERTION_SORT_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   Insertion sort algorithm - basic implementation
 *
 * @param begin         start of range
 * @param end           end of range
 * @param comparator    comparator function
 */
template<typename Iterator,
    typename Comparator = std::less<
        typename std::iterator_traits<Iterator>::value_type>
>
void insertion_sort(Iterator begin, Iterator end, Comparator comparator = Comparator()) {
  using std::swap;

  auto itr = begin;
  for (std::advance(itr, 1); itr != end; std::advance(itr, 1)) {
    std::rotate(std::upper_bound(begin, itr, *itr), itr, std::next(itr));
  }
};

} // algo::sort namespace

} // algo namespace

#endif //ALGO_INSERTION_SORT_H
