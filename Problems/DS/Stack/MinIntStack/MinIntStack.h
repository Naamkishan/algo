#ifndef ALGO_MAXINTSTACK_H
#define ALGO_MAXINTSTACK_H

#include <stdexcept>
#include <stack>

namespace algo {

namespace problems {

/**
 * @brief   MinIntStack: A stack of integers which other than the default stack operations
 *          also have a min api to show the current min element that is present in the current stack.
 *
 *          The max operation has time complexity of O(1) and space complexity of O(1)
 */
class MinIntStack {
 public:

  /**
   * @brief     Push an element into the stack. Compute the current min element of the stack after push operation
   * @param value : Value pushed into the stack
   */
  void push(int value) {
    if(stack_.empty()) {
      cur_min_ = value;
    } else if(cur_min_ > value) {
      auto new_elem = (2 * value) - cur_min_;
      cur_min_ = value;
      value = std::move(new_elem);
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

    // return the value popped as it is if it was the last element or has value smaller than min
    if((cur_min_ < value) || stack_.empty())
      return value;

    // setup the cur min
    auto elem = cur_min_;
    cur_min_ = (2 * cur_min_) - value;
    return elem;
  }

  /**
   * @brief     Returns the current min element of the stack. Throws an exception if stack is empty
   * @return    int
   */
  int min() {
    if(stack_.empty())    throw std::out_of_range("Underflow!");
    return cur_min_;
  }

  std::size_t  size() const { return stack_.size(); }

 private:
  std::stack<int>   stack_;
  int               cur_min_;
};

} // namespace algo::problems

} // namespace algo

#endif //ALGO_MAXINTSTACK_H
