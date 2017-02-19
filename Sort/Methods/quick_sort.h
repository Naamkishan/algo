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
template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type>
>
auto partition_container(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<RandomIter>::difference_type;

  DistanceType length = std::distance(begin, end);

  auto pivot{begin};

  // now partition the current list into two using the pivot's value
  auto low{begin};     std::advance(low, 1);
  auto high{end};      std::advance(high, -1);

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
      if(!comparator(*pivot, *high))   break;
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
template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type>
>
void quick_sort(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {

  //TODO: Random shuffle the container contents before starting out to sort

  // sort only if the list has 2 or more elements
  if(std::distance(begin, end) > 1) {
    auto partition = partition_container(begin, end, comparator);
    quick_sort(begin, partition, comparator);
    quick_sort(std::next(partition), end, comparator);
  }
};

namespace using_std {

template<typename RandomIter,
    typename Comparator  = std::less<
        typename std::iterator_traits<RandomIter>::value_type>
>
void quick_sort(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {
  if(begin == end)  return;

  auto pivot = *std::next(begin, std::distance(begin, end) >> 1);
  auto left_end = std::partition(begin,
                                 end,
                                 [=](const auto& elem) { return comparator(elem, pivot); });
  auto right = std::partition(left_end,
                              end,
                              [=](const auto& elem) { return !comparator(pivot, elem); });

  quick_sort(begin, left_end);
  quick_sort(right, end);
}

} // namespace algo::sort::using_std

} // namespace algo::sort

} // namespace algo

#endif //ALGO_QUICK_SORT_H
