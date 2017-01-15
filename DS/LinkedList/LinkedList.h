
#ifndef ALGO_DS_LINKEDLIST_H
#define ALGO_DS_LINKEDLIST_H

#include <stdexcept>

namespace DS {

/**
 * @brief   A simple non-thread safe implementation of a singly linked list
 */
template<typename T>
class LinkedList {

 private:
  struct Node {
    T     data_;
    Node* next_;

    Node(const T& data, Node* next = nullptr) : data_(data), next_{next} {}
    Node(const T&& data, Node* next = nullptr) : data_(std::move(data)), next_{next} {}
    Node(const Node&& other) : data_(std::move(other.data_)), next_(other.next_) { other.next_ = nullptr;}

   private:
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;
  };


 public:
  LinkedList() : head_{nullptr} {}

  // Manipulators
  LinkedList& push_back(const T& value) {
    Node *node = new Node(value);
    append_node(node);
    return *this;

  }

  LinkedList& push_back(const T&& value) {
    Node *node = new Node(std::move(value));
    append_node(node);
    return *this;
  }


  LinkedList& push_front(const T& value) {
    head_ = new Node(value, head_);
    return *this;
  }

  LinkedList& push_front(const T&& value) {
    head_ = new Node(std::move(value), head_);
    return *this;
  }

  auto pop_front() {
    auto value = front();
    remove_node(head_);
    return value;
  }

  auto pop_back() {
    auto value = back();
    remove_node(tail());
    return value;

  }

  void swap(LinkedList& other) noexcept {
    std::swap(other.head_, head_);
  }

  void clear() {
    while(!empty()) { pop_front(); }
  }

  // accessors
  T& front() {
    if(empty()) throw std::out_of_range("Underflow");
    return head_->data_;
  }

  T& back() {
    if(empty()) throw std::out_of_range("Underflow");
    return tail()->data_;
  }

  // properties
  std::size_t size() const {
    std::size_t size{0};
    for(Node* cur = head_; cur; cur = cur->next_) { ++size; }
    return size;
  }

  bool empty() const { return (head_ == nullptr); }

 private:

  Node* tail() {
    Node* tail = head_;
    if(tail) {
      for(; tail->next_; tail = tail->next_);
    }
    return tail;
  }

  void append_node(Node* node) {
    Node** tail = &head_;
    for(Node* entry; entry = *tail; tail = &entry->next_);
    *tail = node;
  }

  void remove_node(Node* key) {
    Node** target = &head_;
    for(Node* itr; itr = *target; target = &itr->next_) {
      if(itr == key) {
        *target = itr->next_;
        delete itr;
        return;
      }
    }
  }

 private:
  Node        *head_;
};

} // namespace DS

#endif // ALGO_DS_LINKEDLIST_H
