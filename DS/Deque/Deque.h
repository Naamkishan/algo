#ifndef ALGO_DEQUE_H
#define ALGO_DEQUE_H

#include <iterator>
#include <vector>

namespace DS {



template <typename T,
    template<typename> class Container = std::vector>
class Deque {
 public:

  // methods
  void push_back(const T& value);
  void emplace_back(T&& value);
  void push_front(const T& value);
  void emplace_front(T&& value);

  auto pop_front();
  auto pop_back();

  // properties
  bool        empty() const { return container_.empty(); }
  std::size_t size()() const { return container_.size(); }

 private:
  Container<T>    container_;
};

} // namespace DS

#endif //ALGO_DEQUE_H
