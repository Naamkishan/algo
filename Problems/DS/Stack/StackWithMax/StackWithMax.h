#ifndef ALGO_STACKWITHMAX_H
#define ALGO_STACKWITHMAX_H

#include <Stack.h>

namespace algo {

namespace problems {

template <typename T,
    typename Comparator = std::less<T>
    >
class StackWithMax {
  class MaxStack {
    typename DS::Stack<T>  max_;
    Comparator    comparator_;
   public:
    MaxStack(Comparator comparator = Comparator()) : comparator_{comparator} {}

    void push(T& value) {
      auto cur_max = value;
      if(max_.size()) {
        auto prev_max = max_.pop();
        if (comparator_(value, prev_max))
          cur_max = prev_max;
        max_.push(prev_max);
      }
      max_.push(cur_max);
    }

    auto pop() {
      return max_.pop();
    }
  };

 public:
  void push(T& value)   {
    stack_.push(value);
    max_.push(value);
  }

  auto pop() {
    auto val = stack_.pop();
    max_.pop();
    return val;

  }

  auto max() {
    T max = max_.pop();
    max_.push(max);
    return max;
  }

  std::size_t size() const { return stack_.size(); }

 private:
  DS::Stack<T>            stack_;
  MaxStack                max_;
};


} // namespace algo::problems

} // namespace algo

#endif //ALGO_STACKWITHMAX_H
