#ifndef ALGO_DS_LINKEDLIST_H
#define ALGO_DS_LINKEDLIST_H

#include <cassert>
#include <iterator>
#include <stdexcept>

namespace DS {

// forward declarations
template<typename T> class LinkedList;
template<typename T> class LinkedListIterator;
template<typename T> class ConstLinkedListIterator;


namespace detail {

/**
 * @brief   ListNode : this is the DS that is being used internally by the Linked List
 */
template<typename T>
struct Node {
  T     data_;
  Node* next_;

  Node(const T& data, Node* next = nullptr) : data_(data), next_{next} {}
  Node(const T&& data, Node* next = nullptr) : data_(std::move(data)), next_{next} {}
  Node(const Node&& other) : data_(std::move(other.data_)), next_(other.next_) { other.next_ = nullptr;}

  T& reference() { return data_; }
  const T& reference() const { return data_; }
  T* pointer() { return &data_; }
  T* const pointer() const { return &data_; }

 private:
  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;
};

} // namespace DS::detail

/**
 * @brief   LinkedListIterator : STL compliant iterator class for LinkedList
 */
template<typename T>
class LinkedListIterator :
    public std::iterator<std::forward_iterator_tag,
                         LinkedList<T>,
                         typename LinkedList<T>::difference_type,
                         typename LinkedList<T>::pointer,
                         typename LinkedList<T>::reference>
{
  friend class LinkedList<T>;
  friend class ConstLinkedListIterator<T>;

  // concepts
  using reference = typename LinkedList<T>::const_reference;
  using pointer = typename LinkedList<T>::const_pointer;

 private:
  // ensure that only the container has access to its creation
  LinkedListIterator() : node_{nullptr} {}
  LinkedListIterator(detail::Node<T>* node) : node_{node} {}

 public:
  // exposed iterator methods
  /**
   * @brief     operator * : return the reference of the underlying element
   * @return    reference
   */
  reference operator*() {
    assert(node_ != nullptr);
    return node_->reference();
  }

  /**
   * @brief     operator -> : return the pointer of the underlying element
   * @return    pointer
   */
  pointer operator->() {
    assert(node_ != nullptr);
    return node_->pointer();
  }

  /**
   * @brief     operator++ : move to the next element of the linked list
   * @return    iterator
   */
  const LinkedListIterator& operator++() {
    node_ = node_->next_;
    return *this;
  }

  /**
   * @brief     operator++ : postfix move to the next element of the linked list
   * @return    iterator : temporary
   */
  const LinkedListIterator& operator++(int) {
    LinkedListIterator tmp = *this;
    node_ = node_->next_;
    return tmp;
  }

  /**
   * @brief operator== : equality check
   * @param other
   * @return bool
   */
  bool operator==(const LinkedListIterator& other) const {
    return (this->node_ == other.node_);
  }

  /**
   * @brief operator!= : inequality check
   * @param other
   * @return bool
   */
  bool operator!=(const LinkedListIterator& other) const {
    return (this->node_ != other.node_);
  }

 private:
  typename detail::Node<T>*    node_;
};


/**
 * @brief   ConstLinkedListIterator : STL compliant const_iterator class for LinkedList
 */
template<typename T>
class ConstLinkedListIterator :
    public std::iterator<std::forward_iterator_tag,
                         LinkedList<T>,
                         typename LinkedList<T>::difference_type,
                         typename LinkedList<T>::const_pointer,
                         typename LinkedList<T>::const_reference>
{
  friend class LinkedList<T>;

 public:
  // concepts
  using reference = typename LinkedList<T>::const_reference;
  using pointer = typename LinkedList<T>::const_pointer;

 private:
  // ensure that only the container has access to its creation
  ConstLinkedListIterator() : node_{nullptr} {}
  ConstLinkedListIterator(detail::Node<T>* node) : node_{node} {}
  ConstLinkedListIterator(LinkedListIterator<T>& iter) : node_{iter.node_} {}

 public:
  // exposed iterator methods
  /**
   * @brief     operator * : return the reference of the underlying element
   * @return    reference
   */
  reference operator*() const {
    assert(node_ != nullptr);
    return node_->reference();
  }

  /**
   * @brief     operator -> : return the pointer of the underlying element
   * @return    pointer
   */
  pointer operator->() const {
    assert(node_ != nullptr);
    return node_->pointer();
  }

  /**
   * @brief     operator++ : move to the next element of the linked list
   * @return    iterator
   */
  const ConstLinkedListIterator& operator++() {
    node_ = node_->next_;
    return *this;
  }

  /**
   * @brief     operator++ : postfix move to the next element of the linked list
   * @return    iterator : temporary
   */
  const ConstLinkedListIterator& operator++(int) {
    ConstLinkedListIterator tmp = *this;
    node_ = node_->next_;
    return tmp;
  }

  /**
   * @brief operator== : equality check
   * @param other
   * @return bool
   */
  bool operator==(const ConstLinkedListIterator& other) const {
    return (this->node_ == other.node_);
  }

  /**
   * @brief operator!= : inequality check
   * @param other
   * @return bool
   */
  bool operator!=(const ConstLinkedListIterator& other) const {
    return (this->node_ != other.node_);
  }


 private:
  const typename detail::Node<T>*    node_;
};

// Helper functions
template<typename T>
bool operator==(const ConstLinkedListIterator<T>& const_itr, const LinkedListIterator<T>& itr) {
  ConstLinkedListIterator<T> tmp{itr};
  return tmp == const_itr;
}

template<typename T>
bool operator!=(const ConstLinkedListIterator<T>& const_itr, const LinkedListIterator<T>& itr) {
  ConstLinkedListIterator<T> tmp{itr};
  return tmp != const_itr;
}

template<typename T>
bool operator==(const LinkedListIterator<T>& itr, const ConstLinkedListIterator<T>& const_itr) {
  ConstLinkedListIterator<T> tmp{itr};
  return tmp == const_itr;
}

template<typename T>
bool operator!=(const LinkedListIterator<T>& itr, const ConstLinkedListIterator<T>& const_itr) {
  ConstLinkedListIterator<T> tmp{itr};
  return tmp != const_itr;
}

/**
 * @brief   A simple non-thread safe implementation of a singly linked list - STL compliant
 */
template<typename T>
class LinkedList : public std::allocator<T> {

  friend class LinkedListIterator<T>;
  friend class ConstLinkedListIterator<T>;

 public:
  // concepts
  using value_type = typename std::allocator<T>::value_type;
  using pointer = typename std::allocator<T>::pointer;
  using const_pointer = typename std::allocator<T>::const_pointer;
  using reference = typename std::allocator<T>::reference;
  using const_reference = typename std::allocator<T>::const_reference;
  using size_type = typename std::allocator<T>::size_type;
  using difference_type = typename std::allocator<T>::difference_type;

  using iterator = LinkedListIterator<T>;
  using const_iterator = ConstLinkedListIterator<T>;

/* TODO: Make this a doubly linked circular list
  typedef std::reverse_iterator<const_iterator>      const_reverse_iterator;
  typedef std::reverse_iterator<iterator>            reverse_iterator;
*/

 public:
  LinkedList() : head_{nullptr} {}

  // iterators
  iterator begin() { return LinkedListIterator<T>{head_}; }
  const_iterator cbegin() const { return ConstLinkedListIterator<T>{head_}; }
  iterator end() { return LinkedListIterator<T>{nullptr}; }
  const_iterator cend() const { return ConstLinkedListIterator<T>(nullptr); }

  // Manipulators
  LinkedList& push_back(const T& value) {
    detail::Node<T> *node = new detail::Node<T>(value);
    append_node(node);
    return *this;

  }

  LinkedList& emplace_back(const T &&value) {
    detail::Node<T> *node = new detail::Node<T>(std::move(value));
    append_node(node);
    return *this;
  }


  LinkedList& push_front(const T& value) {
    head_ = new detail::Node<T>(value, head_);
    return *this;
  }

  LinkedList& emplace_front(const T &&value) {
    head_ = new detail::Node<T>(std::move(value), head_);
    return *this;
  }

  value_type pop_front() {
    auto value = front();
    remove_node(head_);
    return value;
  }

  value_type pop_back() {
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
  reference front() {
    if(empty()) throw std::out_of_range("Underflow");
    return head_->data_;
  }

  reference back() {
    if(empty()) throw std::out_of_range("Underflow");
    return tail()->data_;
  }

  // properties
  size_type size() const {
    std::size_t size{0};
    for(detail::Node<T>* cur = head_; cur; cur = cur->next_) { ++size; }
    return size;
  }

  bool empty() const { return (head_ == nullptr); }

 private:

  detail::Node<T>* tail() {
    detail::Node<T>* tail = head_;
    if(tail) {
      for(; tail->next_; tail = tail->next_);
    }
    return tail;
  }

  void append_node(detail::Node<T>* node) {
    detail::Node<T>** tail = &head_;
    for(detail::Node<T>* entry; entry = *tail; tail = &entry->next_);
    *tail = node;
  }

  void remove_node(detail::Node<T>* key) {
    detail::Node<T>** target = &head_;
    for(detail::Node<T>* itr; itr = *target; target = &itr->next_) {
      if(itr == key) {
        *target = itr->next_;
        delete itr;
        return;
      }
    }
  }

 private:
  detail::Node<T>        *head_;
};

/*

namespace std {

template<>
struct iterator_traits<LinkedListIterator> {
  using iterator_category = typename LinkedListIterator::iterator_category;
  using value_type = typename LinkedListIterator::value_type;
  using difference_type = typename LinkedListIterator::difference_type;
};

template<>
struct iterator_traits<ConstLinkedListIterator > {
  using iterator_category = typename ConstLinkedListIterator::iterator_category;
  using value_type = typename ConstLinkedListIterator::value_type;
  using difference_type = typename ConstLinkedListIterator::difference_type;
};

}
*/

} // namespace DS


#endif // ALGO_DS_LINKEDLIST_H
