#ifndef ALGO_LINKEDLIST_H
#define ALGO_LINKEDLIST_H

namespace DS {

template<typename T>
class LinkedList {

 public:
  LinkedList() {}

  // Manipulators
  LinkedList& push_back(const T&& value);
  LinkedList& push_front(const T&& value);

  auto pop_front();
  auto pop_back();

  // accessors
  T& front();
  T& back();

  // properties
  std::size_t size() const;
  bool empty();
};

} // namespace DS

#endif //ALGO_LINKEDLIST_H
