#ifndef ALGO_PRIORITYQUEUE_H
#define ALGO_PRIORITYQUEUE_H

#include <functional>
#include <vector>
#include <stdexcept>

namespace algo {

namespace problems {

namespace DS {

namespace PriorityQueue {

template<typename T,
    typename Comparator = std::less<T>,
    template <typename...> class Container = std::vector
>
class PriorityQueue {
 public:
  PriorityQueue(Comparator comparator = Comparator()) : comparator_{comparator} {}

  /**
   * @brief     inserts item at the end of the binary heap and bubbles it up to the appropriate position
   * @param     item : lvalue item
   */
  void enqueue(const T &item) {
    queue_.push_back(item);
    swim(std::next(queue_.end(), -1));
  }

  /**
   * @brief     emplaces item at the end of the binary heap and bubbles it up to the appropriate position
   * @param     item : rvalue item
   */
  void enqueue(T &&item) {
    queue_.emplace_back(item);
    swim(std::next(queue_.end(), -1));
  }

  /**
   * @brief     Removes the root (top) element
   * @return    The previous root element (ie, the root of the heap prior to the pop operation)
   */
  auto dequeue() -> T {
    auto top = root();
    auto last = std::next(queue_.end(), -1);
    std::iter_swap(queue_.begin(), last);
    queue_.pop_back();

    sink(queue_.begin());  // sink ROOT

    return top;
  }

  /**
   * @brief     Gets the root element of the queue
   * @throws    std::range_error if attempted on
   * @return    root element
   */
  auto root() const -> T {
    underflow_check();

    return *queue_.begin();
  }

  /**
   * @brief gets the size of the queue
   * @return    size of the queue
   */
  auto size() const -> typename Container<T>::size_type {
    return queue_.size();
  }

  /**
   * @brief     checks if the underlying container is empty
   * @return    true if empty
   */
  bool empty() const {
    return queue_.empty();
  }

 private:
  /**
   * @brief     checks for underflow
   * @throws    std::range_error iff queue is empty
   */
  constexpr void underflow_check() const throw(std::range_error)  {
    if (this->empty())
      throw std::range_error("underflow");
  }

  /**
   * @brief     takes the item (as pointed by itr) and pushes it up the heap till it reaches a position that satisfies the current heap order
   * @param     itr : iterator to the position of the element that needs to be bubbled up
   */
  void swim(typename Container<T>::iterator itr) {
    auto current = std::distance(queue_.begin(), itr);
    // nowhere to swim if the element is at root
    if(current == 0)
      return;
    auto parent = (current - 1) >> 1; // root is 0 based
    auto begin{queue_.begin()};

    while (current > 0) {
      if (comparator_(*std::next(begin, current), *std::next(begin, parent)))
        return; // binary heap order satisfied

      std::iter_swap(std::next(begin, current), std::next(begin, parent));

      // move up the heap
      current = parent;
      parent = (current - 1) >> 1;
    }
  }

  /**
   * @brief     takes the item (as pointed by itr) and pushes down the heap till it reaches a position that satisfies the current heap order
   * @param     itr : iterator to the position of the element that needs to sink
   *
   * The root always sits at position 0
   */
  void sink(typename Container<T>::iterator itr) {
    auto current = std::distance(queue_.begin(), itr);
    auto child = (current + 1) << 1;
    auto mid = (size() - 1) >> 1;   // index of mid

    while (child < size()) {
      if (comparator_(*std::next(queue_.begin(), child),
                      *std::next(queue_.begin(), child - 1))) {
        --child;  // point to the left child
      }

      // check for binary heap order
      if(comparator_(*std::next(queue_.begin(), child), *std::next(queue_.begin(), current)))
        return;

      std::iter_swap(std::next(queue_.begin(), child), std::next(queue_.begin(), current));

      // move down the heap
      current = child;
      child = (current + 1) << 1;
    }

    // special handling for heaps whose last node points is left
    if (((size() & 1) == 0) && // even numbered heap range
        (current == mid)) { // current pointing to mid
      --child;  // child now points to left branch

      // swap only if binary heap order is violated
      if(!comparator_(*std::next(queue_.begin(), child), *std::next(queue_.begin(), current))) {
        std::iter_swap(std::next(queue_.begin(), child), std::next(queue_.begin(), current));
      }
    }
  }

  Comparator comparator_;
  Container<T> queue_;
};

} // algo::problems::DS::PriorityQueue
} // algo::problems::DS
} // algo::problems
} // algo


#endif //ALGO_PRIORITYQUEUE_H
