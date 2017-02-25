#ifndef ALGO_RANDQ_H
#define ALGO_RANDQ_H

#include <random>
#include <stdexcept>
#include <vector>


namespace DS {

/**
 * @brief   RandomisedQueue: Implementation similar to Stack/Queue. Except, item is removed in a random fashion
 *
 * @tparam      T  : Supported Data Type
 * @tparam      Container : STL compliant data structure
 */
template<typename T,
    template <typename ...> class Container = std::vector
    >
class RandomisedQueue {
 public:
  RandomisedQueue() : mt_{rand_dev_()} {}

  /**
   * @brief enqueue : push into the randomised queue
   * @param value
   */
  void enqueue(const T& value) { container_.push_back(value); }
  /**
   * @brief emplace : push an RValue into the randomised queue
   * @param value
   */
  void emplace(T&& value) { container_.emplace_back(value); }

  /**
   * @brief sample : return the reference to the element which would have been removed
   * @return reference
   */
  typename Container<T>::const_reference sample() const {
    if(empty())   throw std::out_of_range("Underflow");

    typename Container<T>::const_iterator itr = iterator();
    return *itr;
  }

  /**
   * @brief dequeue : return the reference to the element which is being popped
   * @return T
   */
  auto dequeue() {
    if(empty())   throw std::out_of_range("Underflow");

    auto iter = iterator();
    auto value = *iter;

    container_.erase(iter);
    return value;
  }

  /**
   * @brief iterator : returns the underlying container's iterator to any random element of the RandomisedQueue
   * @return iterator of the underlying container
   */
  typename Container<T>::iterator iterator() {
    if(empty())   return container_.end();

    return std::next(container_.begin(), rand_gen());
  }

  typename Container<T>::const_iterator iterator() const {
    if(empty())   return container_.cend();

    return std::next(container_.cbegin(), rand_gen());
  }

  /**
   * @brief size : returns the current size of the underlying container
   * @return    std::size_t
   */
  std::size_t  size() const { return container_.size(); }

  /**
   * @brief empty: returns true if the underlying container is empty
   * @return    bool
   */
  bool empty() const { return container_.empty(); }

 private:

  std::size_t rand_gen() const {
    std::uniform_int_distribution<std::size_t>  dist(0, size() - 1);
    return dist(mt_);
  }

  Container<T>    container_;

  std::random_device                    rand_dev_;
  mutable std::mt19937                  mt_;
};

} // namespace DS

#endif //ALGO_RANDQ_H
