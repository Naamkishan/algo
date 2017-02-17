#ifndef ALGO_SELECTION_SORT_H
#define ALGO_SELECTION_SORT_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   basic implementation of bubble sort
 * @param begin     start of range
 * @param end       end of range
 * @param compare   comparator function
 */
template<typename Iterator,
    typename Compare = std::less<
        typename std::iterator_traits<Iterator>::value_type>
>
void bubble_sort(Iterator begin, Iterator end, Compare compare = Compare()) {
  using std::swap;
  Iterator min;
  for (auto itr = begin; itr != end; std::advance(itr, 1)) {
    min = std::min_element(itr, end, compare);
    swap(*min, *itr);
  }
};

} // alog::sort namespace

} // algo namespace

#endif //ALGO_SELECTION_SORT_H
