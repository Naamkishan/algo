#ifndef ALGO_SLL_INSTERSECT_H
#define ALGO_SLL_INSTERSECT_H

#include <LinkedList.h>
#include <Stack.h>


namespace algo {

namespace problems {

template<typename T>
DS::detail::Node<T>* get_intersection_point(DS::detail::Node<T>* left, DS::detail::Node<T>* right) {
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

} // namespace algo::problems


} // namespace algo

#endif //ALGO_SLL_INSTERSECT_H
