#ifndef ALGO_QUEUE_H
#define ALGO_QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue {
 public:
  void enqueue(const T& value) {
    container_.push_back(value);
  }

  void enqueue(const T&& value) {
    container_.push_back(std::move(value));
  }

  auto dequeue() {
    auto value = std::move(container_.front());
    container_.pop_front();
    return value;
  }

  bool empty() const { return container_.empty(); }

  std::size_t size() const { return container_.size(); }

 private:
  DS::LinkedList<T>  container_;
};

#endif //ALGO_QUEUE_H
