#ifndef ALGO_MERGE_SORT_H_H
#define ALGO_MERGE_SORT_H_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

template<typename InputIter,
    typename OutputIter,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIter>::value_type>
>
OutputIter merge(InputIter start1, InputIter end1,    // first container
                  InputIter start2, InputIter end2,   // second container
                  OutputIter result,
                  Comparator comparator = Comparator()) {
  ForwardIter left{start1}, right{start2};

  while((start1 != end1) && (start2 != end2)) {
    if(comparator(*start1, *start2)) {
      *result = *start1;
      std::advance(start1, 1);
    } else {
      *result = *start2;
      std::advance(start2, 1);
    }

    std::advance(result, 1);
  }

  return std::copy(start1, end1,
                   std::copy(start2, end2, output));
}

/**
 * @brief   Merge Sort on any stl compatible container
 *
 * @tparam  InputIter
 * @tparam  OutputIter
 * @tparam  Comparator  compare function
 *
 * @param start         Beginning of range
 * @param end           End of range
 * @param output        Sorted Output
 * @param comparator    defaults to std::less
 */
template<typename InputIter,
    OutputIter output,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIter>::value_type>
    >
void merge_sort(InputIter start, InputIter end, OutputIter output, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<InputIter>::difference_type;

  DistanceType mid = std::distance(start, end)/2;
  if(mid) {
    OutputIter left = merge_sort(start, std::next(start, mid), comparator);
    OutputIter right = merge_sort(std::next(start, mid + 1), end, comparator);
    algo::sort::merge(left, std::next(left, mid),
                       right, end, output);
  }

}

} // namespace algo::sort

} // namespace algo

#endif //ALGO_MERGE_SORT_H_H
