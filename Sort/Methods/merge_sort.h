#ifndef ALGO_MERGE_SORT_H_H
#define ALGO_MERGE_SORT_H_H

#include <algorithm>
#include <iterator>

namespace algo {

namespace sort {

/**
 * @brief   Performs in place merging of two branches (must be stl compatible)
 *
 * @tparam  ForwardIterator     Iterator type of container
 * @tparam  Comparator          Sorting Predicate
 *
 * @param left_start    Range start of left branch
 * @param left_end      Range end of left branch
 * @param right_start   Range start of right branch
 * @param right_end     Range end of right branch
 * @param comparator    Comparator functor
 * @return
 */
template<typename ForwardIterator,
    typename Comparator = std::less<
        typename std::iterator_traits<ForwardIterator>::value_type>
>
void inplace_merge(ForwardIterator left_start, ForwardIterator left_end,    // left branch [left_start, left_end)
                   ForwardIterator right_start, ForwardIterator right_end,  // right branch [right_start, right_end)
                   Comparator comparator = Comparator()) {
  using std::swap;
  // loop only till both the branches are traversible
  while((left_start != left_end) && (right_start != right_end)) {
    if(comparator(*right_start, *left_start)) {
      swap(*right_start, *left_start);

      // ensure the right branch is always sorted even after the swap
      for(ForwardIterator itr{right_start};
          (itr != right_end) && (comparator(*std::next(itr, 1), *itr)); // iterate as long as predicate condition is true
          std::advance(itr, 1)) {
        swap(*itr, *std::next(itr, 1));
      }
    } else {
      std::advance(right_start, 1);
    }

    std::advance(left_start, 1);
  }
}


/**
 * @brief   Merge Sort on any stl compatible container.
 *          Merging is done inplace
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
void inplace_merge_sort(ForwardIterator start, ForwardIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<ForwardIterator>::difference_type;
  using Type = typename std::iterator_traits<ForwardIterator>::value_type;
  using VectorT = std::vector<Type>;

  DistanceType length = std::distance(start, end);

  if(length > 1) {
    DistanceType mid = length >> 1; // divide by 2 using left shift

    inplace_merge_sort(start, std::next(start, mid), comparator);
    inplace_merge_sort(std::next(start, mid), end, comparator);
    inplace_merge(start, std::next(start, mid), std::next(start, mid), end, comparator);
  }
}



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
