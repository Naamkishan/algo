#ifndef ALGO_FAIRWORKLOAD_H
#define ALGO_FAIRWORKLOAD_H

#include <algorithm>
#include <iterator>
#include <numeric>


/**
 *
 * @param begin         : start of range
 * @param end           : end of range
 * @param workers       : number of workers in amongst which work is to be divided
 * @param comparator    : Functor for comparing values; default to std::less
 * @param accumulator   : Functor for accumulating values; defaults to std::plus
 * @return
 */
template<typename ForwardIterator,
    typename Comparator = std::less<
        std::iterator_traits<ForwardIterator>::value_type>,  // comparator predicate
    typename Accumulator = std::plus<
        std::iterator_traits<ForwardIterator>::value_type>  // comparator predicate
>
auto get_most_work(ForwardIterator begin, ForwardIterator end,    // range of container
                   std::iterator_traits<ForwardIterator>::value_type workers,
                   Comparator comparator = Comparator(),
                   Accumulator accumulator = Accumulator()) {
  using DistanceType = typename std::iterator_traits<ForwardIterator>::difference_type;
  using Type = std::iterator_traits<ForwardIterator>::value_type;

  ForwardIterator low = std::max_element(begin, end);
  Type high = std::accumulate(begin, end, Type{}, accumulator);

  while(*low < high) {
    DistanceType mid = std::distance(begin, end) >> 1;  // right shift >> divide by 2

  }
}


#endif //ALGO_FAIRWORKLOAD_H
