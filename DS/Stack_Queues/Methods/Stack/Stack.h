#include <LinkedList.h>

namespace DS {

/**
 * @brief   Stack : implements the standard methods (as per Coursera course)
 *
 * @tparam  T           :   data type of Stack
 * @tparam  Container   :   data structure used internally to hold elements. Should be compliant with std containers like list and vector
 */
template<typename T,
    template <typename> class Container = LinkedList
>
class Stack {
 public:
  Stack() {}

  void push(const T &value) {
    container_.push_back(value);
  }

  void push(const T &&value) {
    container_.push_back(std::move(value));
  }

  auto pop() {
    auto value(std::move(container_.back())); // auto -> implicitly RValue
    container_.pop_back();
    return value; // RVO still applies to reduce two moves to one
  }

  bool empty() const { return container_.empty(); }
  std::size_t size() const { return container_.size(); }

 private:
  Container<T> container_;
};

} // namespace DS