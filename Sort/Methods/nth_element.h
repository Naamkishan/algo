#ifndef ALGO_SORT_NTH_ELEMENT_H_
#define ALGO_SORT_NTH_ELEMENT_H_

#include <cassert>
#include <iterator>

namespace algo {

namespace sort {

namespace nth_element {

/**
 * @brief   nth_element     :  sorts the given range till nth position
 *
 * @param begin : start of range
 * @param end   : end of range
 * @param pivot : the n-th element
 * @param comparator : comparator functor. default to std::less
 * @return iterator of the nth-element
 */
template<typename RandomIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type >
    >
RandomIterator nth_element(RandomIterator begin,
                           RandomIterator end,
                           RandomIterator pivot,
                           Comparator comparator = Comparator()) {
  if(begin == end)
    return begin;

  using DistanceType = typename std::iterator_traits<RandomIterator>::difference_type;

  auto low{begin};
  auto high = std::next(end, -1);
  DistanceType pos = std::distance(begin, itr);

  std::iter_swap(high, itr);  // pivot element now in default last position
  --high;                     // adjust high to make room for pivot

  while(true) {
    for(; low != high; ++low) {
      // move only when low is less than pivot
      if(comparator(*pivot, *low))
        break;
    }

    for(; low != high; --high) {
      if(!comparator(*pivot, *high))
        break;
    }

    // unless the low and high pointers cross each other, swap high and low to make the list iterable again
    if(low != high) {
      std::iter_swap(low, high);
    } else {
      std::iter_swap(pivot, high);
      break;
    }

  }

  auto pivot_pos = std::distance(begin, high);  // high is the new pivot

  if(pivot_pos < pos)
    return nth_element(high, end, pivot, comparator);
  else if(pos > pivot_pos)
    return nth_element(begin, high, pivot, comparator);

  return high;
}


} // nth_element

} // algo::sort

} // algo


#endif // ALGO_SORT_NTH_ELEMENT_H_