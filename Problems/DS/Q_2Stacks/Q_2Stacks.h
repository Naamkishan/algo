#ifndef ALGO_Q_2STACKS_H
#define ALGO_Q_2STACKS_H

#include <Stack.h>
#include <stdexcept>

namespace algo {

namespace problems {

template<typename T>
class Q_2Stacks {
 public:

  void enqueue(const T& obj) {
    while(!stack_.empty()) {
      swapper_.push(dequeue());
    }

    stack_.push(obj);
    while(swapper_.size()) {
      stack_.push(swapper_.pop());
    }
  }

  void enqueue(const T&& obj) {
    while(!stack_.empty()) {
      swapper_.push(dequeue());
    }

    stack_.push(obj);
    while(swapper_.size()) {
      stack_.push(swapper_.pop());
    }
  }

  auto dequeue() {
    if(size() == 0)   throw std::runtime_error("Underflow!!");
    return stack_.pop();
  }

  constexpr std::size_t size() { return stack_.size(); }

 private:
  DS::Stack<T>   stack_;
  DS::Stack<T>   swapper_;
};

} // namespace algo::problems

} // namespace

#endif //ALGO_Q_2STACKS_H
