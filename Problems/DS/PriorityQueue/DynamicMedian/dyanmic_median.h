#ifndef ALGO_DYANMIC_MEDIAN_H
#define ALGO_DYANMIC_MEDIAN_H

#include <functional>
#include <stdexcept>

#include "priority_queue.h"

namespace algo {

namespace problems {

namespace DS {

namespace PriorityQueue {

/**
 * @brief   Class that accepts data and determines median dynamically
 * @tparam  T                   : underlying data type for this data structure; defaults to int
 * @tparam  LessComparator      : comparator functor for managing max heap; defaults to float
 * @tparam  GreaterComparator   : comparator functor for managing min heap
 * @tparam  MedianType          : supported data type for calculation of median (e.g. float for queue of integers)
 *
 * This data structure supports constant time access for median of the priority queue; while
 * enqueueing and dequeueing operations take logarithmic time.
 *
 * @details This class internally maintains two heaps; one with values less than or equal to the effective median and \
 *          the other with values greater than the effective median. The root of both the heaps will always contain the effective median
 *
 * @ingroup heap_algorithms
 */
template<typename T = int,
    typename MedianType = float,
    typename LessComparator = std::less<T>,
    typename GreaterComparator = std::greater<T>
>
class DynamicMedian {
  /**
   * Enum class to select min/max PriorityQueue depending on which one is bigger
   */
  enum class PQSelect {
    GREATER,    // max_median_ heap is bigger
    SMALLER,    // min_median_ heap is bigger
    EQUAL       // both heaps are of equal size
  };

 public:

  DynamicMedian(LessComparator less_comp = LessComparator(),
                GreaterComparator greater_comp = GreaterComparator() ) :
      less_comp_(less_comp), greater_comp_(greater_comp) {}

  /**
   * @brief Enqeueue an object in the priority queue. Updates the median.
   * @param item
   */
  void enqueue(const T& item) {
    T value = item;
    enqueue(std::move(value));
  }

  /**
   * @brief Enqeueue an object in the priority queue. Updates the median.
   * @param r-value item
   */
  void enqueue(T&& item) {
    if(max_median_.empty()) {
      max_median_.enqueue(std::move(item));
    } else {
      if (greater_comp_(item, max_median_.root())) {
        max_median_.enqueue(std::move(item));
      } else {
        min_median_.enqueue(std::move(item));
      }
    }

    adjustPQ();
  }


  /**
   * @brief Dequeue the root of the bigger heap
   * @return    the median before deletion of the median.
   */
  auto dequeue() -> T&& {
    check_underflow();

    auto median_value = median();

    auto pq = which_pq();
    if(pq == PQSelect::GREATER)
      max_median_.dequeue();
    else
      min_median_.dequeue();

    adjustPQ();

    return std::move(median_value);
  }

  /**
   * @breif     gets the median of the current queue
   * @return    depending on the data type, the value of median may or may not be rounded off
   */
  auto median() const -> MedianType&& {
    check_underflow();

    MedianType median_value;

    switch(which_pq()) {
      case PQSelect::GREATER:
        median_value = static_cast<MedianType>(max_median_.root());
        break;
      case PQSelect::SMALLER:
        median_value = static_cast<MedianType>(min_median_.root());
        break;
      case PQSelect::EQUAL:
        median_value = (static_cast<MedianType>(min_median_.root()) + static_cast<MedianType>(max_median_.root()))/2;
        break;
      default:
        throw std::runtime_error("Unreachable code!");
    }

    return std::move(median_value);
  }

  /**
   * @brief gets the size of the queue
   * @return    the size of the queue
   */
  auto size() const -> std::size_t {
    return min_median_.size() + max_median_.size();
  }

  /**
   * @brief checks if the DynamicMedian is empty of not
   * @return    true if empty
   */
  bool empty() const {
    return (max_median_.empty() && min_median_.empty());
  }

 private:

  /**
   * @brief     ensures that the PQs sizes are never greater than 1
   */
  void adjustPQ() {
    int size_diff = min_median_.size() - max_median_.size();

    // max size diff allowed is 1 (between the heaps)
    if(size_diff > 1) { // min heap is larger
      auto median = min_median_.dequeue();
      max_median_.enqueue(std::move(median));
    } else if(size_diff < -1) {  // max heap is larger
      auto median = max_median_.dequeue();
      min_median_.enqueue(std::move(median));
    }
  }

  /**
   * @brief Throws and exception if any attempt is done on an empty queue
   * @throws    std::range_error if the queue is empty
   */
  void check_underflow() const {
    if(empty())
      throw std::range_error("Underflow!");
  }

  /**
   * @brief     selects the priority queue which is of bigger size
   * @return    PQSelect enum value based on which PQ is bigger/equal
   */
  PQSelect which_pq() const {
    if(min_median_.size() > max_median_.size())
      return PQSelect::SMALLER;
    if(max_median_.size() > min_median_.size())
      return PQSelect::GREATER;

    return PQSelect::EQUAL;
  }

  // members
  GreaterComparator                     greater_comp_;
  LessComparator                        less_comp_;

  PriorityQueue<T, GreaterComparator>   min_median_;
  PriorityQueue<T, LessComparator>      max_median_;

};


} // algo::problems::DS::PriorityQueue

} // algo::problems::DS

} // algo::median

} // algo

#endif //ALGO_DYANMIC_MEDIAN_H
