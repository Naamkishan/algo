#include "UnionFind.h"
#include <algorithm>


UnionFind::UnionFind(size_t nodes) : container_{nodes}, sub_tree_size{nodes} {
  while(nodes) {
    --nodes;
    container_[nodes] = nodes;
  }
  std::fill(sub_tree_size.begin(), sub_tree_size.end(), 1);
}


size_t UnionFind::root(size_t i) {
  std::size_t root_index = container_[i];

  while(container_[root_index] != root_index)
    root_index = container_[root_index];

  return root_index;
}


void UnionFind::set_root(size_t node, size_t root) {
  container_[node] = root;
  sub_tree_size[root] += sub_tree_size[node];
}


void UnionFind::set_union(size_t p, size_t q) {
  std::size_t root_p = root(p);
  std::size_t root_q = root(q);

  if(root_p != root_q) {
    if(sub_tree_size[root_p] > sub_tree_size[root_q]) {
      set_root(root_q, root_p);
    } else {
      set_root(root_p, root_q);
    }
  }
}


