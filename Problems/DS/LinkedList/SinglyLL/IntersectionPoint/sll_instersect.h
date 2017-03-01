#ifndef ALGO_SLL_INSTERSECT_H
#define ALGO_SLL_INSTERSECT_H

#include <LinkedList.h>
#include <Stack.h>


namespace algo {

namespace problems {

/**
 * @brief   Use stack. If the lists intersects, the last node has to be same for both. Order : O(n + m)
 * @param left
 * @param right
 * @return  address of the point of intersection or nullptr if none
 */
template<typename T>
DS::detail::Node<T>* get_intersection_point_use_stack(DS::detail::Node<T>* left, DS::detail::Node<T>* right) {
  using NodeStack = DS::Stack<DS::detail::Node<T>*>;
  NodeStack left_stack, right_stack;

  for(auto itr = left; itr; itr = itr->next_)   left_stack.push(itr);
  for(auto itr = right; itr; itr = itr->next_)   right_stack.push(itr);

  DS::detail::Node<T>* pt{nullptr};
  DS::detail::Node<T>* pt_cur;
  while(!left_stack.empty() && !right_stack.empty()) {
    pt_cur = left_stack.pop();
    if(pt_cur != right_stack.pop())
      break;

    pt = pt_cur; // the updated potential intesection point
  }

  return pt;
}


template<typename T>
std::size_t list_size(DS::detail::Node<T>* list) {
  std::size_t size = 0;
  for(; list; list = list->next_)
    ++size;
  return size;
}

/**
 * @brief   get the intersection point of two lists by checking the last possible common nodes
 * @param left
 * @param right
 * @param diff  : difference of length of two lists
 * @return
 */
template<typename T>
DS::detail::Node<T>* get_intersection_point(DS::detail::Node<T>* left, DS::detail::Node<T>* right) {
  if(left && right) {
    int diff = list_size(left) - list_size(right);

    DS::detail::Node<T>** head = (diff > 0) ? &left : &right;
    diff = abs(diff);

    while(diff) {
      *head = (*head)->next_;
      --diff;
    }

    // now left and right are in sync wrt to last "size - diff" positions
    while(left && right) {
      if(left == right)
        return left;

      // update the pointers
      left = left->next_;
      right = right->next_;
    }

  }

  return nullptr;
}

} // namespace algo::problems


} // namespace algo

#endif //ALGO_SLL_INSTERSECT_H
