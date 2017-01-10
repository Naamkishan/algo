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
  LinkedList() : head_{nullptr}, size_{0} {}

  // Manipulators
  LinkedList& push_back(const T& value) {
    Node *node = new Node(value);
    update_tail(node);
    return *this;

  }

  LinkedList& push_back(const T&& value) {
    Node *node = new Node(value);
    update_tail(node);
    return *this;
  }


  LinkedList& push_front(const T& value) {
    Node *node = new Node(value, head_);
    update_head(node);
    return *this;
  }

  LinkedList& push_front(const T&& value) {
    Node *node = new Node(value, head_);
    update_head(node);
    return *this;
  }

  auto pop_front() {
    Node* node = head_;
    delete_node(head_); // the head node is indexed 1
    auto value = std::move(node->data_);
    delete node;
    return value;
  }

  auto pop_back() {
    Node* node = tail_;
    delete_node(tail_); // the head node is indexed 1
    auto value = std::move(node->data_);
    delete node;
    return value;

  }

  void swap(LinkedList& other) noexcept {
    std::swap(other.head_, head_);
    std::swap(other.tail_, tail_);
  }

  void clear() {
    while(!empty()) {
      pop_front();
    }
  }

  // accessors
  T& front() { return head_->data_; }
  T& back() { return tail_->data_; }

  // properties
  std::size_t size() const { return size_; };
  bool empty() { return (size_ == 0); }

 private:
  void update_head(Node* node) {
    head_ = node;
    if(!tail_)  tail_ = head_;
    ++size_;
  }

  void update_tail(Node* node) {
    if(!tail_) {
      update_head(node);
    } else {
      tail_->next_ = node;
      tail_ = node;
      ++size_;
    }
  }

  void delete_node(Node* which_node) {
    // underflow check
    if(empty())
      throw std::out_of_range("LinkedList underflow!");

    Node* prev = nullptr;
    Node* next = head_->next_;
    for(Node* curr{head_}; curr; curr = curr->next_, prev = curr, next = curr->next_) {
      if(curr == which_node) {
        if(prev)  prev = next;
        // remove node from list
        delete curr;
        --size_;
        // update head and tail
        if(!prev) head_ = next;
        if(!next) tail_ = head_;
        return;
      }
    }

    // node not found in list
    throw std::out_of_range("Node not in LinkedList");
  }

 private:
  Node        *head_;
  Node        *tail_;
  std::size_t  size_;
};

} // namespace DS

#endif // ALGO_DS_LINKEDLIST_H
