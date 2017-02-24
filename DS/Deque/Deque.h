#ifndef ALGO_DEQUE_H
#define ALGO_DEQUE_H

#include <vector>
#include <stdexcept>

namespace DS {

/**
 * @brief   A simple implementation of Deque. The supplied underlying container has to be stl complaint
 *
 * @tparam  T           :   Data Type
 * @tparam  Container   :   Underlying data structure used by Deque. This has to be STL compliant
 */
template<typename T,
    template <typename...> class Container = std::vector
>
class Deque {
 public:
  // methods

  /**
   * @brief push_back : push element at the rear
   * @param value
   */
  void push_back(const T& value)  { container_.push_back(value); }
  /**
   * @brief emplace_back: push an element (RValue) at the rear
   * @param value
   */
  void emplace_back(T&& value)    { container_.emplace_back(value); }
  /**
   * @brief push_front  : push an element at the front
   * @param value
   */
  void push_front(const T& value) { container_.insert(container_.begin(), value); }
  /**
   * @brief emplace_front : push an element (RValue) at the front
   * @param value
   */
  void emplace_front(T&& value)   { container_.emplace(container_.begin(), value); }

  /**
   * @brief     pop_front : takes out the first element from the underlying container and returns it to the caller
   * @return    T
   */
  auto pop_front()  {
    if(empty())   throw std::out_of_range("Underflow!");

    auto value = container_.front();
    container_.erase(container_.begin());

    return value;
  }

/**
   * @brief     pop_back : takes out the last element from the underlying container and returns it to the caller
   * @return    T
   */
  auto pop_back() {
    if(empty())   throw std::out_of_range("Underflow!");

    auto value = container_.back();
    container_.pop_back();
    return value;
  }

  // properties
  /**
   * @brief     empty : checks to find if the container is empty
   * @return    bool
   */
  bool        empty() const { return container_.empty(); }
  /**
   * @brief     size : returns the current size of the underlying container
   * @return    std::size_t
   */
  std::size_t size() const { return container_.size(); }

  /**
   * @category  iterator
   * @brief begin : return the underlying container's iterator at the front
   * @return STL compliant iterator
   */
  auto begin() { return  container_.begin(); }
  /**
   * @category  iterator
   * @brief cbegin : return the underlying container's const iterator at the front
   * @return STL complaint const_iterator
   */
  auto cbegin() const { return  container_.begin(); }
  /**
   * @category  iterator
   * @brief end : return the underlying container's iterator at the rear
   * @return STL compliant iterator
   */
  auto end() { return  container_.end(); }
  /**
   * @category  iterator
   * @brief cend : return the underlying container's const iterator at the rear
   * @return STL complaint const_iterator
   */
  auto cend() const { return  container_.end(); }

 private:
  Container<T>    container_;
};



} // namespace DS

#endif //ALGO_DEQUE_H
