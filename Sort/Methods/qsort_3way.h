#ifndef ALGO_QSORT_3WAY_H
#define ALGO_QSORT_3WAY_H

#include <iterator>

namespace {
  enum class CompOperation {
    LESS,
    EQUAL,
    GREATER
  };

  template<typename T, typename Comparator>
  CompOperation compare(const T& a, const T& b, Comparator comparator) {
    if(comparator(a, b))
      return CompOperation::LESS;
    if(comparator(b, a))
      return CompOperation::GREATER;

    return CompOperation::EQUAL;
  };
}

namespace algo {

namespace sort {

/**
 * @brief   3-way more efficient partitioning. This can handle both duplicate and distinct keys.
 *
 *  This partitioning does a 3 way partitioning:
 *      i)      range of values on the left that are less than the partitioning element
 *      ii)     range of values in the middle that are equal to the partitioning element (can be one or more elements)
 *      iii)    range of values in the right which are greater than the partitioning element
 *
 * @param low : start of range
 * @param high   : end of range (this is a pointer to the element past the actual range of elements that need to be partitioned)
 * @param comparator : predicate which will be used for partitioning
 * @return      return [pivot start, pivot end)
 */
template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type
    >
>
auto partition_3way(RandomIter low,
                    RandomIter high,
                    Comparator comparator = Comparator()) {
  auto current{low};

  while(current != high){
    CompOperation comp_op = compare(*current, *low, comparator);

    switch (comp_op) {
      case CompOperation::LESS:
        // current element is less than low (the pivot)
        std::iter_swap(low, current);
        ++low;
        ++current;
        break;
      case CompOperation::GREATER:
        // current is greater than low (the pivot)
        std::iter_swap(current, --high);
        break;
      case CompOperation::EQUAL:
        // update the new pivot position
        ++current;
        break;
    }
  }

  // ensure that we move low iterator to the first pivot element of the equal range
  return std::make_pair(low, current);
}

template<typename RandomIter,
    typename Comparator = std::less<
        typename std::iterator_traits<RandomIter>::value_type
    >
>
void quicksort_3way(RandomIter begin, RandomIter end, Comparator comparator = Comparator()) {
  // sorting makes sense only when there are at least 2 elements
  if(std::distance(begin, end) > 1) {
    auto partition = partition_3way(begin, end, comparator);
    quicksort_3way(begin, partition.first);
    quicksort_3way(partition.second, end);
  }
};

} // namespace algo::sort

} // namespace algo

#endif //ALGO_QSORT_3WAY_H
