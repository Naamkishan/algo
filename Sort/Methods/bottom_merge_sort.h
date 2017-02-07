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

  // the out loop will create the sublist on which the inner loop will work
  for(DistanceType sl_length = {1}; sl_length < length; sl_length <<= 1) {
    std::advance(sl_itr, sl_length);
    for(DistanceType lo = {0}; lo < (length - sl_length); lo += (sl_length + sl_length)) {
      auto left = std::next(begin, lo);
      auto mid = std::next(left, sl_length);
      VectorT left_aux(left, mid);
      VectorT right_aux(mid,
                        std::next(
                            mid,
                            std::min(sl_length, length - (std::distance(begin, mid)))
                        )
      );
      std::merge(left_aux.begin(), left_aux.end(),
                 right_aux.begin(), right_aux.end(),
                 std::next(begin, lo),
                 comparator);
    }
  }

}


} // namespace algo::sort

} // namespace algo

#endif //ALGO_BOTTOM_MERGE_SORT_H
