#ifndef ALGO_UNIONFIND_H
#define ALGO_UNIONFIND_H

#include <vector>

class UnionFind {
 public:
  UnionFind(std::size_t nodes);

  bool connected(std::size_t p, std::size_t q) { return root(p) == root(q); }
  void set_union(std::size_t p, std::size_t q);

 private:
  std::size_t root(std::size_t i);
  void set_root(std::size_t node, std::size_t root);

 private:
  std::vector<std::size_t> container_;
  std::vector<std::size_t> sub_tree_size_;
};

#endif //ALGO_UNIONFIND_H
