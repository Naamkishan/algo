#ifndef ALGO_QUICK_SORT_H
#define ALGO_QUICK_SORT_H

#include <iterator>

namespace algo {

namespace sort {

/**
 *
 * @param begin     start of range
 * @param end       end of range
 * @return          pivot point
 */
template<typename ForwardIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIterator>::value_type>
>
auto partition_container(ForwardIterator begin, ForwardIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<ForwardIterator>::difference_type;

  DistanceType length = std::distance(begin, end);

  ForwardIterator pivot{begin};

  // now partition the current list into two using the pivot's value
  ForwardIterator low{begin};    std::advance(low, 1);
  ForwardIterator high{end};    std::advance(high, -1);

  // iterate till the low and high pointers do not cross each other
  while(true) {
    // move the low pointer till it reaches a value
    for(; low != high; std::advance(low, 1)) {
      if(comparator(*pivot, *low))   break;
    }


    /* Move the high pointer to the left till it encounters one of the following scenarios:
     *    (i) value pointed by high pointer is not greater than pivot
     *    (ii) high has crossed low pointer
     */
    for(; high != pivot; std::advance(high, -1)) {
      if(comparator(*high, *pivot))   break;
    }

    // whenever pointers cross break out
    if(std::distance(low, high) <= 0)
      break;

    // swap the elements to make the list traversable again
    std::swap(*low, *high);
  }

  std::swap(*high, *pivot);

  return high;  // this is now the partition point
}

/**
 *
 * @param begin         start of range
 * @param end           end of range
 * @param comparator    comparsion function : defaults to std::less
 */
template<typename ForwardIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIterator>::value_type>
>
void quick_sort(ForwardIterator begin, ForwardIterator end, Comparator comparator = Comparator()) {

  //TODO: Random shuffle the container contents before starting out to sort

  // sort only if the list has 2 or more elements
  if(std::distance(begin, end) > 1) {
    ForwardIterator partition = partition_container(begin, end, comparator);
    quick_sort(begin, partition, comparator);
    quick_sort(std::next(partition), end, comparator);
  }
};

} // namespace algo::sort

} // namespace algo

#endif //ALGO_QUICK_SORT_H
