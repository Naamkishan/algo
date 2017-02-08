#ifndef ALGO_FISHER_YATES_H
#define ALGO_FISHER_YATES_H

#include <iterator>
#include <random>
#include <chrono>

namespace algo {

namespace problems {

/**
 * @brief   Modern Fisher Yates Algorithm - O(n)
 *
 * This performs inplace randomisation of an given container
 * http://www.geeksforgeeks.org/shuffle-a-given-array/
 *
 * @tparam BiIter   Bidirectional iterator of the container
 * @param start     Beginning of range for source container
 * @param end       End of range for source container
 */
template<typename BiIter>
void fisher_yates_shuffle(BiIter start, BiIter end) {
  using std::swap;
  using DifferenceType = typename std::iterator_traits<BiIter>::difference_type;

  unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::default_random_engine rand_eng(seed);

  DifferenceType  length = std::distance(start, end);

  BiIter rstart = std::next(end, -1);
  BiIter rend = start;
  DifferenceType  randomised_index;

  for(BiIter itr = rstart; itr != rend; std::advance(itr, -1)) {
    std::uniform_int_distribution<DifferenceType> distr(0, std::distance(start, std::next(itr, -1)));
    randomised_index = distr(rand_eng);

    swap(*itr, *std::next(start, randomised_index));
  }
}


} // namespace algo::problems

} // namespace algo

#endif //ALGO_FISHER_YATES_H
