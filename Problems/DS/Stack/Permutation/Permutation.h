#ifndef ALGO_PERMUTATION_H
#define ALGO_PERMUTATION_H

#include <algorithm>
#include <iterator>
#include <vector>

#include <randq.h>

namespace algo {

namespace problems {

template <typename T,
    template <typename ...> class Container = std::vector
>
class Permutation {
 public:
  /**
   * @brief     enqueue : Enqueues the input range provided to underlying RandomisedQueue
   *
   * @tparam    ForwardIterator : the iterator type of the input range should be ForwardIterator
   *
   * @param     begin : start of input range
   * @param     end : end of input range
   *
   * @return    void
   */
  template<typename ForwardIterator>
  void enqueue(ForwardIterator begin, ForwardIterator end) {
    while(begin != end) {
      rand_q_.enqueue(*begin);
      std::advance(begin, 1);
    }
  }



  /**
   * @brief permutation : gives out the number of permutation for the provided input
   *        throws exception if
   *
   * @tparam OutputIterator : Should point to buffer having at least \"number\"
   *
   * @param number : Number of permutations requested
   * @param out : results to be copied to this
   */
  template<typename OutputIterator>
  void permutation(std::size_t number, OutputIterator out) {
    if(empty())   throw std::out_of_range("Underflow");

    for(std::size_t idx = {0}; idx < number; ++idx) {
      *out++ = rand_q_.sample();
    }
  }

  // properties
  /**
   * @brief     size : returns the size of the underlying RandomisedQueue container
   * @return    std::size_t
   */
  std::size_t size() const { return rand_q_.size(); }
  /**
   * @brief     empty : returns true if underlying container is empty
   * @return    bool
   */
  bool empty() const { return rand_q_.empty(); }

 private:
  DS::RandomisedQueue<T, Container>   rand_q_;
};

} // namespace algo::problems

} // namespace algo

#endif //ALGO_PERMUTATION_H
