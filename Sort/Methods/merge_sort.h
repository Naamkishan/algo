#ifndef ALGO_MERGE_SORT_H_H
#define ALGO_MERGE_SORT_H_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   Merge Sort on any stl compatible container. Uses stl's merge method
 *
 * @tparam  ForwardIterator
 * @tparam  Comparator  compare function
 *
 * @param start         Beginning of range
 * @param end           End of range
 * @param comparator    defaults to std::less
 * @return  Nothing
 */
template<typename ForwardIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIterator>::value_type>
>
void merge_sort(ForwardIterator start, ForwardIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<ForwardIterator>::difference_type;
  using Type = typename std::iterator_traits<ForwardIterator>::value_type;
  using VectorT = std::vector<Type>;

  DistanceType length = std::distance(start, end);

  if(length > 1) {
    DistanceType mid = length >> 1; // divide by 2 using left shift

    merge_sort(start, std::next(start, mid), comparator);
    merge_sort(std::next(start, mid), end, comparator);
    VectorT aux(start, end); // copy the values in the auxiliary buffer
    std::merge(aux.begin(), std::next(aux.begin(), mid), std::next(aux.begin(), mid), aux.end(), start, comparator);
  }
}

} // namespace algo::sort

} // namespace algo

#endif //ALGO_MERGE_SORT_H_H
