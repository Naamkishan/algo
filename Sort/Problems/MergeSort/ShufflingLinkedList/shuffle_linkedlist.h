#ifndef ALGO_SHUFFLE_LINKEDLIST_H
#define ALGO_SHUFFLE_LINKEDLIST_H

#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

#include <LinkedList.h>

namespace {

template <typename T>
bool lists_equal(DS::detail::Node<T>* first, DS::detail::Node<T>* second) {
  while(first && second) {
    if(first->data_ != second->data_)
      return false;
    first = first->next_;
    second = second->next_;
  }

  return true;
}

/**
 * @brief   Adds a node at the end of the list
 * @param head : head of the linked list
 * @param node : the node that needs to be attached
 */
template<typename T>
void append_node(DS::detail::Node<T>* &head, DS::detail::Node<T>* node) {
  DS::detail::Node<T>** tail{&head};

  while(*tail)  tail = &(*tail)->next_;

  *tail = node;
}

/**
 * Detach the node from the linked list; effectively removing the node
 * @param head : head of the linked list
 * @param node : the node that needs to be taken out from the linked list
 */
template <typename T>
void detach_node(DS::detail::Node<T>* &head, DS::detail::Node<T>* node) {
  for(DS::detail::Node<T>** cur{&head}; *cur; cur = &(*cur)->next_) {
    if(*cur == node) {
      *cur = (*cur)->next_;
      return;
    }
  }
}

/**
 * @brief   Attach sublist immediately after the given node.
 * @param current : The key node after which the sublist is to be attached
 * @param node : the sublist that needs to be attached
 */
template<typename T>
void insert_node_after(DS::detail::Node<T>* &current, DS::detail::Node<T>* &node) {
  if(current) {
    DS::detail::Node<T>** node_tail = &node;
    while(*node_tail)   node_tail = &(*node_tail)->next_;
    (*node_tail)->next_ = current->next_;
    current->next_ = node;
  }
}

/**
 * Breaks the linked list into two at the node pointed by new_head
 * @param head : head of the original linked list that needs to be spliced
 * @param new_head  : head of the new linked list.
 */
template<typename T>
void splice(DS::detail::Node<T>* &head, DS::detail::Node<T>* &new_head) {
  DS::detail::Node<T>** tail{&head};

  while(*tail && (*tail != new_head))
    tail = &(*tail)->next_;

  *tail = nullptr;
}

/**
 * returns the length of the linked list
 * @param head
 * @return
 */
template<typename T>
std::size_t length(DS::detail::Node<T>* head) {
  std::size_t size{0};

  while(head) {
    ++size;
    head = head->next_;
  }

  return size;
}

/**
 * @bnief   copies source to target (a new linked list with exact same copy of data and order)
 * @param src
 * @param target
 */
template <typename T>
void copy_list(DS::detail::Node<T>* src, DS::detail::Node<T>** target) {
  DS::detail::Node<T>* node;
  while(src)  {
    append_node(*target, new DS::detail::Node<T>(src->data_));
    src = src->next_;
  }
}

template<typename T>
void clear_list(DS::detail::Node<T>* head) {
  DS::detail::Node<T>* tmp;
  while(head) {
    tmp = head;
    head = head->next_;
    delete tmp;
  }
}

}

namespace algo {

namespace problems {

template<typename T>
using Idx_Node_Pair = typename std::pair<std::size_t, DS::detail::Node<T>* >;

/**
 * @brief   merges the
 * @param begin
 * @param partition
 * @param end
 */
template <typename RandomIterator>
void merge_by_key(RandomIterator begin, RandomIterator partition, RandomIterator end, RandomIterator aux) {
  auto mid{partition};

  while((begin != partition) && (mid != end)) {
    if((*begin).first < (*mid).first) {
      *aux = *begin;
      ++begin;
    } else {
      *aux = *mid;
      ++mid;
    }
    ++aux;
  }

  while(begin != partition)
    *aux++ = *begin++;

  while(mid != end)
    *aux++ = *mid++;
}


template <typename RandomIterator>
void merge_sort_by_key(RandomIterator begin, RandomIterator end, RandomIterator aux) {
  auto length = std::distance(begin, end);
  if(length > 1) {
    auto mid = length >> 1;
    RandomIterator partition = std::next(begin, mid);
    merge_sort_by_key(begin, partition, aux);
    merge_sort_by_key(partition, end, aux);
    merge_by_key(begin, partition, end, aux);
  }
};

/**
 * @brief   Shuffle the linked list using divide and conquer (similar to that of mergesort)
 * @param head : the head of the list that needs to be shuffled
 * @param seed : seed used for the random engine (use 0 for using default random_device)
 */
template<typename T>
void shuffle_ll(DS::detail::Node<T>* &head, std::size_t seed) {
  auto ll_length = length(head);

  // no point in shuffling if the list contains less than 2 nodes
  if(ll_length < 2)
    return;


  // the DS that will hold a random number assigned to the iterator of the linked list's node
  std::pair<std::size_t, DS::detail::Node<T>* > idx_rand_pair;

  // the aux buffer
  using Idx_Node_Pair_VectorT = std::vector<Idx_Node_Pair<T> >;
  Idx_Node_Pair_VectorT ref_container;
  Idx_Node_Pair_VectorT  aux(ll_length);

  // crate a random distribution
  if(!seed) {
    std::random_device  rd;
    seed = rd();
  }
  std::mt19937  re(seed);
  std::uniform_int_distribution<std::size_t> uni_dist(1, ll_length);

  for(auto itr = head; itr != nullptr; itr = itr->next_) {
    ref_container.push_back(std::make_pair(uni_dist(re), itr));
  }

  // now perform a merge sort on the aux values
  merge_sort_by_key(std::begin(ref_container), std::end(ref_container), std::begin(aux));

  // now the ref_container is properly shuffled. time to update the linked list
  auto ref_cont_itr = std::begin(ref_container);
  auto prev_elem = ref_cont_itr++;
  while(ref_cont_itr != std::end(ref_container)) {
    std::swap(ref_cont_itr->second->data_, prev_elem->second->data_);
    prev_elem = ref_cont_itr++;
  }
}


} // namespace algo::problems

} // namespace algo

#endif //ALGO_SHUFFLE_LINKEDLIST_H
