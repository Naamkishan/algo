#ifndef ALGO_NTS_N_BOLTS_H
#define ALGO_NTS_N_BOLTS_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

namespace problems {

namespace SortCrossRefRanges {

/**
 * @brief   compares two different data types (if operator< is overloaded for such comparison)
 * @tparam Type1 : Data Type for left
 * @tparam Type2 : Data Type for right
 * @param left
 * @param right
 * @return  true iff left < right
 */
template<typename Type1,
         typename Type2>
struct Less{
  bool operator()(const Type1 &left, const Type2 &right) const {
    return (left < right);
  }
};


/**
 * @brief   partitions a range using the pivot provided as an argument
 *
 * @param low           : start of range
 * @param high          : end of range
 * @param pivot         : used for partitioning the range referencing a different range
 * @param comparator    : comparator function. Default to std::less
 * @return              A RandomIterator that points to interator containing the value of the pivot
 */
template<typename RandomIterator1,
    typename RandomIterator2,
    typename Comparator1 = Less<typename std::iterator_traits<RandomIterator1>::value_type,
                               typename std::iterator_traits<RandomIterator2>::value_type>,
    typename Comparator2 = Less<typename std::iterator_traits<RandomIterator1>::value_type,
                               typename std::iterator_traits<RandomIterator2>::value_type>

>
auto partition_using_pivot(RandomIterator1 low,
                                     RandomIterator1 high,
                                     RandomIterator2 pivot,
                                     Comparator1 comparator1 = Comparator1(),
                                     Comparator2 comparator2 = Comparator2() ) {
  auto equal_itr = low;

  while(low != high) {
    if(comparator1(*low, *pivot)) {
      ++low;
    } else  {
      std::iter_swap(low, --high);
      // save the equal position
      if(!comparator2(*pivot, *high)) { // high now contains low
        // equality condition
        equal_itr = high;
      }
    }
  }

  // ensure that the equal value is at the partition
  std::iter_swap(equal_itr, low);

  return low;
}

/**
 *
 * Sorts two ranges in order. Constraint: pivot for one range has to be taken from the other range and vice versa
 *
 * Assumption: Both the lists for Nuts and Bolts will be identical after sorting.
 *
 * @tparam  RandomIterator1  : Assumed that the iterator passed is a RandomIterator
 * @tparam  RandomIterator2  : Assumed that the iterator passed is a RandomIterator
 * @tparam  Comparator1      : the comparator functor that will provide implementation of comparison using less analogy
 * @tparam  Comparator2      : the comparator functor that will provide implementation of comparison using less analogy
 *
 * @param begin_1    : start of range 1
 * @param end_1      : end of range 1
 * @param begin_2   : start of range 2
 * @param end_2     : end of range 2
 */

template<typename RandomIterator1,
    typename RandomIterator2,
    typename Comparator1 = Less<typename std::iterator_traits<RandomIterator1>::value_type,
                               typename std::iterator_traits<RandomIterator2>::value_type>,
    typename Comparator2 = Less<typename std::iterator_traits<RandomIterator2>::value_type,
                               typename std::iterator_traits<RandomIterator1>::value_type>
>
void sort_cross_ref_ranges(RandomIterator1 begin_1,
                           RandomIterator1 end_1,
                           RandomIterator2 begin_2,
                           RandomIterator2 end_2,
                           Comparator1 comparator1 = Comparator1(),
                           Comparator2 comparator2 = Comparator2() ) {
  // sort only if there's at least two elements in the range; we are taking range 1 as a reference list
  if(std::distance(begin_1, end_1) > 1) {
    // by default take the middle element as pivot
    auto mid = std::distance(begin_2, end_2) >> 1;

    auto partition_1 = partition_using_pivot(begin_1, end_1, std::next(begin_2, mid), comparator1, comparator2);
    auto partition_2 = partition_using_pivot(begin_2, end_2, partition_1, comparator2, comparator1);

    // list1 (begin_1, end_1] is sorted for partition_1
    sort_cross_ref_ranges(begin_1, partition_1, begin_2, partition_2, comparator1, comparator2);
    // list2 (begin_2, end_2] is sorted for partition_2
    sort_cross_ref_ranges(std::next(partition_1), end_1, std::next(partition_2), end_2, comparator1, comparator2);
  }
}

} // algo::sort::problems::SortCrossRefRanges

} // algo::sort::problems

} // algo::sort

} // algo

#endif //ALGO_NTS_N_BOLTS_H
