#include "UnionFind.h"
#include <algorithm>


UnionFind::UnionFind(std::size_t nodes) {
  container_.reserve(nodes);
  sub_tree_size_.reserve(nodes);
  while(nodes) {
    --nodes;
    container_[nodes] = nodes;
  }
  std::fill(sub_tree_size_.begin(), sub_tree_size_.end(), 1);
}


std::size_t UnionFind:: root(std::size_t i) {
  std::size_t root_index = container_[i];

  while(container_[root_index] != root_index) {
    container_[root_index] = container_[container_[root_index]];  // make every node point to its grand parent
    root_index = container_[root_index];
  }

  return root_index;
}


void UnionFind::set_root(std::size_t node, std::size_t root) {
  container_[node] = root;
  sub_tree_size_[root] += sub_tree_size_[node];
}


void UnionFind::set_union(std::size_t p, std::size_t q) {
  std::size_t root_p = root(p);
  std::size_t root_q = root(q);

  if(root_p != root_q) {
    if(sub_tree_size_[root_p] > sub_tree_size_[root_q]) {
      set_root(root_q, root_p);
    } else {
      set_root(root_p, root_q);
    }
  }
}


