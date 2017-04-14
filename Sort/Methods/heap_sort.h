#ifndef ALGO_HEAP_SORT_H
#define ALGO_HEAP_SORT_H

#include <algorithm>
#include <functional>
#include <iterator>

namespace algo {

namespace sort {

namespace binary_heap {

/**
 * @brief   sink the root till it reaches it appropriate position to keep binary heap order
 * @tparam  RandomIterator
 * @tparam  Comparator
 * @param   begin : start of heap range
 * @param   end   : end of heap range
 * @param   comparator
 *
 * @ingroup     heap_algorithms
 */
template<typename RandomIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type>
>
void sink(RandomIterator begin, RandomIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<RandomIterator>::difference_type;

  if(std::distance(begin, end) > 1) {
    const DistanceType total = std::distance(begin, end);     // total number of elements in this sub binary tree
    DistanceType current{0};    // initially points to the root element of the given binary heap range
    DistanceType child = ((current + 1) << 1) - 1;   // make current point to left child; as root is 0 based right child = 2N and left = 2N - 1

    DistanceType mid = (total - 1) >> 1;  // adjustments for 0-based index for root

    while(current < mid) {
      if( (child < (total - 1)) && // our range is 0 based index; ensuring that right child exists
          comparator(*std::next(begin, child), *std::next(begin, child + 1))) {
        ++child;  // right child is greater
      }

      if(!comparator(*std::next(begin, current), *std::next(begin, child)))
        break;

      std::iter_swap(std::next(begin, current), std::next(begin, child));

      // move down the heap
      current = child;
      child = ((current + 1) << 1) - 1;  // child now points to current's left child
    }

    // special handling for left child for even numbered heap with current node pointing to mid
    if( ((total & 1) == 0) &&   // even numbered heap
        (current == mid)) {       // is child pointing to the parent
      if(comparator(*std::next(begin, current), *std::next(begin, child)))
        std::iter_swap(std::next(begin, current), std::next(begin, child));
    }
  }
}


/**
 * This method allows a node (if it has values greater than its parent) to swim up till it finds its suitable position in the heap
 *
 * @tparam RandomIterator
 * @tparam Comparator
 * @param begin : start of range
 * @param elem  : position of node that may need to swim up
 * @param comparator
 */
template<typename RandomIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type>
>
void swim(RandomIterator begin, RandomIterator elem, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<RandomIterator>::difference_type;

  if(std::distance(begin, elem) > 1) {
    DistanceType current = std::distance(begin, elem);  // current node's position
    DistanceType parent;

    // loop till current reaches root position
    while(current) {
      parent = (current - 1) >> 1;  // root occupies position 0
      // break out if heap order is satisfied
      if(!comparator(*std::next(begin, parent),      // parent element
                     *std::next(begin, current)))    // current element
        break;

      std::iter_swap(std::next(begin, parent), std::next(begin, current));
      current = parent;
    }
  }
}

/**
 * @brief       Push \"value\" into heap maintaining the heap order - Taken from STL
 * @tparam RandomIterator
 * @tparam DistanceType
 * @tparam ValueType
 * @tparam Comparator
 * @param begin         : begin of range
 * @param hole_index    : index of range that have memory allocated but no valid object assigned to it
 * @param top_index     : root index for this push
 * @param value         : value to be inserted
 * @param comparator
 */
template<typename RandomIterator, typename DistanceType, typename ValueType, typename Comparator>
void push_heap(RandomIterator begin,
               DistanceType hole_index,
               DistanceType top_index,
               ValueType value,
               Comparator comparator) {
  DistanceType parent = (hole_index - 1) >> 1;

  while((hole_index > top_index ) &&
      comparator(*std::next(begin, parent), value)) {
    *std::next(begin, hole_index) = std::move(*std::next(begin, parent));

    hole_index = parent;
    parent = (hole_index - 1) >> 1;
  }

  *std::next(begin, hole_index) = std::move(value);
}

/**
 * Adjust the current heap for given value - taken from STL
 * @tparam RandomIterator
 * @tparam Comparator
 * @param begin : start of the range
 * @param hole_index: The index which has memory allocated but does not have any valid object
 * @param total_length : total number of elements in the binary heap
 * @param value : value to be inserted
 * @param comparator : compare functor
 */
template <typename RandomIterator, typename DistanceType, typename ValueType, typename Comparator>
void adjust_heap(RandomIterator begin,
                 DistanceType hole_index,
                 DistanceType total_length,
                 ValueType value,
                 Comparator comparator) {

  const DistanceType top_index{hole_index};
  DistanceType right_child{hole_index};

  while( right_child < ((total_length - 1) >> 1) ) { // adjustment done for 0-based indexing of root
    right_child = (right_child + 1) << 1;

    if(comparator(*std::next(begin, right_child), *std::next(begin, right_child - 1) ) ) {
      --right_child;
    }

    *std::next(begin, hole_index) = std::move(*std::next(begin, right_child));
    hole_index = right_child;
  }

  // handling of left child for a range having an even total number of elements
  if( (total_length & 1) == 0 && // check for even number of total elements
      (right_child == ((total_length >> 1) - 1) )  // right child is actually left child here and points to the mid
      ) {
    right_child = ((right_child + 1) << 1) - 1;   // points the the left child; left is always 2N - 1
    *std::next(begin, hole_index) = std::move(*std::next(begin, right_child));
    hole_index = right_child;
  }

  push_heap(begin, hole_index, top_index, std::move(value), comparator);
}


/**
 * @brief   Construct a heap over a range
 * @tparam  RandomIterator
 * @tparam  Comparator : defaults to std::less
 * @param   begin : Start of range
 * @param   end : End of range
 * @param   comparator
 * @ingroup heap_algorithmns
 *
 * This converts the element inside range [begin, end) into a heap
 */
template <typename RandomIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type>
>
void make_heap(RandomIterator begin, RandomIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<RandomIterator>::difference_type;
  using ValueType = typename std::iterator_traits<RandomIterator>::value_type;

  // if the range contains less than 2 elements, its already heap ordered!
  if(std::distance(begin, end) < 2)
    return;

  const DistanceType total = std::distance(begin, end);
  DistanceType parent = (total >> 1) - 1;  // convert to 0 based index for root

  while(true) {
    ValueType element = std::move(*std::next(begin, parent));
    adjust_heap(begin, parent, total, std::move(element), comparator);
    if(parent == 0)
      break;
    --parent;
  }
}

/**
 *  Heap Sort a given range. To get N log N order on sorting provide a RandomIterator.
 *  ForwardIterators will also work but then the order becomes quadratic
 * @tparam RandomIterator
 * @tparam Comparator
 * @param begin
 * @param end
 * @param comparator
 *
 * @ingroup sort
 */
template<typename RandomIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type>
>
void heap_sort(RandomIterator begin, RandomIterator end, Comparator comparator = Comparator()) {
  using DistanceType = typename std::iterator_traits<RandomIterator>::difference_type;
  using ValueType = typename std::iterator_traits<RandomIterator>::value_type;

  if(begin != end) {
    binary_heap::make_heap(begin, end, comparator);

    auto itr{end};
    std::advance(itr, -1);  // make itr point to the last valid element
    while(itr != begin) {
      std::iter_swap(begin, itr); // move the max element to the last element
      binary_heap::sink(begin, itr, comparator); // maintain heap order
      --itr;
    }
  }
}


} // algo::sort::binary_heap

} // algo::sort

} // algo



#endif //ALGO_HEAP_SORT_H
