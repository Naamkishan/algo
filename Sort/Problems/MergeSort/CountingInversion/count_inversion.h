/**
 *
 * Inversion: for i < j; a[i] > a[j] where i, j are within the bounds of array index
 * Example: Sequence: 2, 4, 1, 3, 5
 *              Inversions: (2, 1), (4, 1), (4, 3)
 *              Inversion Count: 3
 *
 */


#ifndef ALGO_COUNTINVERSION_H
#define ALGO_COUNTINVERSION_H

#include <iterator>
#include <set>
#include <vector>

namespace algo {

namespace problems {

/**
 * @brief   : use STL to count the number of inversions
 *
 * Order: best case nlog(n), worst case n^2
 *
 * @param array     : input source
 * @return          : The number of inversions
 */
template<typename T, std::size_t SIZE>
std::size_t count_inversion_stl(T (&array)[SIZE]) {
  std::size_t inversions{0};

  std::set<T>   sorted;
  for(const T& elem : array) {
    sorted.insert(elem);

    // uppert_bound: get the iterator to the first element greater than the element provided as key
    inversions += std::distance(sorted.upper_bound(elem), sorted.end());
  }

  return inversions;
}

/*****************************
 *
 * use Merge Sort Algorithm
 *
 * ***************************/

template<typename RandomIterator>
std::size_t merge_with_env_cnt(RandomIterator begin,
                                         RandomIterator partition,
                                         RandomIterator end, RandomIterator aux) {
  std::size_t inversions{0};

  auto left = begin;
  auto mid = partition;
  auto aux_head = aux;

  // copy to the aux container
  std::copy(left, end, aux);

  while((left != partition) && (mid != end)) {
    // iterate till the first smaller element is encountered in the second sublist (mid)
    while((left != partition) && (*left < *mid)) {
      *aux++ = *left++;
    }

    // if the first sublist has been completely consumed; the remaining right sublist has to be sorted
    if(left == partition)
      break;

    // move on the second sub list till
    if((mid != end) && (*mid < *left)) {
      *aux++ = *mid++;
      inversions += std::distance(left, partition);
    }
  }

  // if second sublist has been consumed but the first remains... copy it to the auxilary buffer
  std::copy(left, partition, aux);
  aux = std::next(aux, std::distance(left, partition));   //update tha aux iterator .. should be its end position
  // if the first sublist has been consume copy the second sublist
  std::copy(mid, end, aux);
  aux = std::next(aux, std::distance(mid, end));   //update tha aux iterator .. should be its end position

  // copy back the sorted list back to the actual container
  std::copy(aux_head, aux, begin);

  return inversions;
}

/**
 * @brief   : use STL to count the number of inversions
 *
 * Order: nlog(n)
 *
 * @param array     : input source
 * @param aux       : temporary buffer used
 * @return          : The number of inversions
 */
template<typename RandomIterator>
std::size_t merge_sort_with_inv_count(RandomIterator begin, RandomIterator end, RandomIterator aux) {
  using Type = typename std::iterator_traits<RandomIterator>::value_type;
  std::size_t inversions{0};

  typename std::iterator_traits<RandomIterator>::difference_type length = std::distance(begin, end);
  if(length > 1) {
    auto partition = length >> 1;
    inversions += merge_sort_with_inv_count(begin, std::next(begin, partition), aux);
    inversions += merge_sort_with_inv_count(std::next(begin, partition), end, aux);
    inversions += merge_with_env_cnt(begin, std::next(begin, partition), end, aux);
  }

  return inversions;
}


} // algo::problems

} // algo

#endif //ALGO_COUNTINVERSION_H
