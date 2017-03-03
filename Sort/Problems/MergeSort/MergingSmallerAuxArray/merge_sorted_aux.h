#ifndef ALGO_MERGE_SORTED_AUX_H
#define ALGO_MERGE_SORTED_AUX_H

#include <algorithm>
#include <array>

namespace algo {

namespace problems {

/**
 * @brief This function would sort an array which is partitioned at SIZE/2.
 *
 * Limitation: Aux array created on stack so will not work on a very large array. Easy Fix: Create on free store ;)
 *
 * Both the left and right partitions are sorted. Howerver, sorting inside either of the partitions are not dependent on the other partition.
 * @param array : the input list (two sorted sublists)
 */
template<typename T, std::size_t SIZE>
void merge_sorted_aux(T (&array)[SIZE]) {
  constexpr std::size_t partition = SIZE >> 1;
  std::array<T, partition>  aux;

  auto itr = std::begin(array);

  // iterate till all elements of the array are sorted
  while(itr != std::end(array)) {
    // if the remaining elements are less than the size of the aux array.. then the list is already sorted
    if(std::distance(itr, std::end(array)) <= aux.size())
      break;

    // copy the left most elements (of size SIZE/2) to the aux array
    std::copy(itr, std::next(itr, aux.size()), aux.begin());
    auto right = std::next(itr, partition);

    // continue to merge till all the aux elements have been merged onto the main list
    auto aux_itr = std::begin(aux);
    do {
      while((aux_itr != std::end(aux)) && (*aux_itr < *right))  {
        *itr = *aux_itr;
        ++itr;
        ++aux_itr;
      }

      while((aux_itr != std::end(aux))      // aux is not exhausted
          && (right != std::end(array))       // right ptr must be bounded inside the array
              && (*right < *aux_itr)) {     // iterate till the right's value is less than aux
        *itr = *right;
        ++itr;
        ++right;
      }

    } while(aux_itr != std::end(aux) && (right != std::end(array))); // iterate till both the sublists are not exhuasted

    // Copy the remaining aux to main list
    std::copy(aux_itr, std::end(aux), itr);
  }
};


} // namespace problems


} // namespace algo

#endif //ALGO_MERGE_SORTED_AUX_H
