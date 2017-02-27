#ifndef ALGO_REVERSE_SLL_H
#define ALGO_REVERSE_SLL_H

#include <cstddef>
namespace algo {

namespace problems {

template<typename T>
struct LinkedList {
  T               data_;
  LinkedList<T>*  next_;

  LinkedList(const T& value, LinkedList* next = nullptr) : data_{value}, next_{next} {}
};

template <typename T>
void add_node(LinkedList<T>* &head, LinkedList<T>* node) {
  LinkedList<T>** target{&head};
  for(; *target; target = &(*target)->next_);
  *target = node;
}

template <typename T>
void clear_list(LinkedList<T>* &head) {
  LinkedList<T>* tmp;
  while(head) {
    tmp = head;
    head = head->next_;
    delete tmp;
  }
}

template <typename T>
std::size_t list_size(LinkedList<T>* head) {
  std::size_t&& length = 0;
  while(head) {
    ++length;
    head = head->next_;
  }

  return length;
}

template <typename T>
bool lists_equal(LinkedList<T>* list1, LinkedList<T>* list2) {
  bool matched{true};

  while(list1 && list2) {
    if(list1->data_ != list2->data_) {
      matched = false;
      break;
    }
    list1 = list1->next_;
    list2 = list2->next_;
  }

  // for exact match .. both the list pointers should be pointing to end of list
  if(matched && (list1 || list2))
    matched = false;

  return matched;
}

template <typename T>
void reverse_list(LinkedList<T>* &head) {
  if(head) {
    LinkedList<T>*  previous = head;
    LinkedList<T>*  current = head->next_;
    LinkedList<T>** new_tail = &head->next_;

    while(*new_tail) {
      *new_tail = current->next_;
      head = current;   // update the head as we move along
      current->next_ = previous;
      // move the prev and current pointers to their next nodes (or the original list)
      previous = current;
      current = *new_tail;
    }
  }
}

} // namespace algo::problems

} // namesapce algo

#endif //ALGO_REVERSE_SLL_H
