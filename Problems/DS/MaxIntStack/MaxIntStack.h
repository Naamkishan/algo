#ifndef ALGO_MAXINTSTACK_H
#define ALGO_MAXINTSTACK_H

#include <limits>
#include <stdexcept>
#include <stack>

namespace algo {

namespace problems {

/**
 * @brief   MaxIntStack: A stack of integers which other than the default stack operations
 *          also have a max api to show the current max element that is present in the current stack.
 *
 *          The max operation has time complexity of O(1) and space complexity of O(1)
 */
class MaxIntStack {
 public:

  /**
   * @brief     Push an element into the stack. Compute the current max element of the stack after push operation
   * @param value : Value pushed into the stack
   */
  void push(int value) {
    if(stack_.empty()) {
      cur_max_ = value;
    } else if(cur_max_ < value) {
      // ensure that element to be inserted is bigger than the cur_max_ element
      auto elem = (2 * value) - cur_max_;
      cur_max_ = value;
      value = elem;
    }

    stack_.push(value);
  }

  /**
   * @brief     Pops the last entered element of the stack. Throws an exception if stack is empty
   * @return    int
   */
  int pop() {
    if(stack_.empty())    throw std::out_of_range("Underflow!");

    auto value = stack_.top();
    stack_.pop();

    if(stack_.empty() || cur_max_ > value) {
      return value;
    }

    auto elem = cur_max_;
    cur_max_ = (2 * cur_max_) - value;

    return elem;
  }

  /**
   * @brief     Returns the current max element of the stack. Throws an exception if stack is empty
   * @return    int
   */
  int max() {
    if(stack_.empty())    throw std::out_of_range("Underflow!");
    return cur_max_;
  }

  std::size_t size() const { return stack_.size(); }

 private:
  std::stack<int>   stack_;
  int               cur_max_;
};

} // namespace algo::problems

} // namespace algo

#endif //ALGO_MAXINTSTACK_H
