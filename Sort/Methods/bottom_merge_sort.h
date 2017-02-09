#ifndef ALGO_BOTTOM_MERGE_SORT_H
#define ALGO_BOTTOM_MERGE_SORT_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   Bottom Out Merge Sort: Performs merge sort using loops
 *
 * @tparam  ForwardIterator:    ForwardIterator of the container which has to be sorted
 * @tparam  Comparator:         Comparison functor using which sorting is done. Defaults to std::less
 *
 * @param begin:                Start of range
 * @param end:                  End of range
 * @param comparator:           Comparison functor
 */
template<typename ForwardIterator,
  typename Comparator = std::less<
    typename std::iterator_traits<ForwardIterator>::value_type>
  >
void bottom_out_merge_sort(ForwardIterator begin, ForwardIterator end,  // the range of the container
                          Comparator comparator=Comparator()) {
  using Type = typename std::iterator_traits<ForwardIterator>::value_type;
  using VectorT = std::vector<Type>;
  using DistanceType = typename std::iterator_traits<ForwardIterator>::difference_type;

  auto length = std::distance(begin, end);
  ForwardIterator sl_itr{begin};

  // create a buffer memory
  VectorT aux(length);


  // the out loop will create the sublist on which the inner loop will work
  for(DistanceType sl_length = {1}; sl_length < length; sl_length <<= 1) {
    std::advance(sl_itr, sl_length);
    for(DistanceType lo = {0}; lo < (length - sl_length); lo += (sl_length + sl_length)) {
      // this operation can be length for a non-random access iterator
      auto sl_right_len = std::min(sl_length,
                              length - lo - sl_length);

      std::copy(std::next(begin, lo),                             // start range of sublist
                std::next(begin, lo + sl_length + sl_right_len),  // end range of sublist
                std::next(aux.begin(), lo));                      // start range of output iterator

      std::merge(std::next(aux.begin(), lo),                              // start range of left buffer
                 std::next(aux.begin(), lo + sl_length),                  // end range of left buffer
                 std::next(aux.begin(), lo + sl_length),                  // start range of right buffer
                 std::next(aux.begin(), lo + sl_length + sl_right_len),   // end range of right buffer
                 std::next(begin, lo),                                    // start range of output iterator
                 comparator);
    }
  }

}


} // namespace algo::sort

} // namespace algo

#endif //ALGO_BOTTOM_MERGE_SORT_H
