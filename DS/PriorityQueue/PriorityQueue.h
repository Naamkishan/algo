#ifndef ALGO_PRIORITYQUEUE_H
#define ALGO_PRIORITYQUEUE_H

#include <functional>
#include <iterator>
#include <stdexcept>
#include <vector>

namespace algo {

namespace DS {

namespace PQ {

/**
 * Implementation of a priority queue using binary heap as the internal sorting mechanism
 * Defaults to Max PQ
 * @tparam T : Data Type of stored objects
 * @tparam Comparator : Priority criteria
 */
template<typename T,
    typename Comparator = std::less<T>
    >
class PriorityQueue {

  using DistanceType = typename std::vector<T>::difference_type;
  constexpr static const DistanceType ROOT_POSITION = 1;

 public:
  PriorityQueue() : comparator_{Comparator()}, queue_{0} {}  // by default create a node which will not be used. root node @ index 1

  // methods

  /**
   * checks if the priority queue is empty
   * @return true if empty
   */
  bool empty() const {  return queue_.size() == 1;  }

  /**
   * Gets the value held by the root element
   * @return root node's value
   */
  auto root() const {
    if(this->empty())
      throw std::runtime_error("Underflow exception!");
    return queue_[ROOT_POSITION];
  }

  /**
   * Inserts an element into the priority queue ensuring heap ordering
   * @param value : value to insert
   */
  void enqueue(const T &value) {
    queue_.push_back(value);

    swim(this->size());
  }

  /**
   * Inserts an RValue element in the queue while maintaining heap ordering
   * @param value : RValue to be pushed inside the priority queue
   */
  void enqueue(const T &&value) {
    queue_.push_back(value);

    swim(this->size());
  }

  /**
   * Removes the root element of the binary heap. Reorders the heap again
   * @return The root element's value
   */
  auto dequeue() {
    if(this->empty())
      throw std::runtime_error("Underflow exception!");

    typename std::vector<T>::iterator last = std::next(queue_.end(), -1);

    // swap the root with last node
    std::iter_swap(std::next(queue_.begin()), last);

    auto value(std::move(queue_.back())); // explicity R-value

    queue_.pop_back();

    // now ensure root node sink to its proper place
    sink(ROOT_POSITION);

    return value; // RVO - rvalue return type
  }

  DistanceType size() const { return queue_.size() - 1; }

 private:
  /**
   * Ensures binary heap order by sinking (moving down) the larger element to its proper place
   * @param index : position of the element that has to be sinked
   */
  void sink(DistanceType index) {
    DistanceType child;

    auto cur{index};
    auto mid = size() >> 1;


    while(cur <= mid) {
      child = cur << 1;

      // left child: child; right child: child + 1
      if( (child < size()) && // ensure that there's a right right before making the comparison
          comparator_(queue_[child], queue_[child + 1]) )
        ++child;  // right child can be the better parent

      if(!comparator_(queue_[cur], queue_[child]))
        return; // child and current satisfy the current heap order

      std::iter_swap(std::next(queue_.begin(), child), std::next(queue_.begin(), cur));

      // move down the heap
      cur = child;
    }
  }

  /**
   * Move up the (larger) element to it proper position by exchanging smaller values.
   * @param index : position of the larger element violating the heap order
   */
  void swim(DistanceType index) {
    auto parent = index >> 1;

    for (auto current{index};
         (current > ROOT_POSITION) && comparator_(queue_[parent], queue_[current]);
         current = parent, parent >>= 1
        ) {
      std::iter_swap(std::next(queue_.begin(), current), std::next(queue_.begin(), parent));
    }
  }

 private:
  Comparator      comparator_;
  std::vector<T>  queue_; // root starts from 1; index 0 is not used
};

} // algo::DS::PQ

} // algo::DS

} // algo


#endif //ALGO_PRIORITYQUEUE_H
