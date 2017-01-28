#ifndef ALGO_INSERTION_SORT_H
#define ALGO_INSERTION_SORT_H

#include <algorithm>
#include <iterator>

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
        typename std::iterator_traits<Iterator>::value_type >
    >
void insertion_sort(Iterator begin, Iterator end, Comparator comparator = Comparator()) {
  using std::swap;

  for(Iterator itr = {begin + 1}; itr != end; itr = std::next(itr)) {
    std::rotate(std::upper_bound(begin, itr, *itr), itr, std::next(itr));
  }
};

} // algo namespace

#endif //ALGO_INSERTION_SORT_H
