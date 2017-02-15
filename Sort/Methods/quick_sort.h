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
template<typename InputIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<InputIterator>::value_type>
>
auto partition_container(InputIterator begin, InputIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<InputIterator>::difference_type;

  DistanceType length = std::distance(begin, end);

  /*
  std::random_device  rand_dev;
  std::default_random_engine  eng(rand_dev());
  std::uniform_int_distribution<int> int_dist(0, length - 1);
  DistanceType pivot_loc = int_dist(eng);

  // swap the pivot's value with first element
  std::swap(*begin, *std::next(begin, pivot_loc));
  */

  InputIterator pivot{begin};

  // now partition the current list into two using the pivot's value
  InputIterator low{begin};    std::advance(low, 1);
  InputIterator high{end};    std::advance(high, -1);

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
template<typename InputIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<InputIterator>::value_type>
>
void quick_sort(InputIterator begin, InputIterator end, Comparator comparator = Comparator()) {

  //TODO: Random shuffle the container contents before starting out to sort

  // sort only if the list has 2 or more elements
  if(std::distance(begin, end) > 1) {
    InputIterator partition = partition_container(begin, end, comparator);
    quick_sort(begin, partition, comparator);
    quick_sort(std::next(partition), end, comparator);
  }
};

} // namespace algo::sort

} // namespace algo

#endif //ALGO_QUICK_SORT_H
