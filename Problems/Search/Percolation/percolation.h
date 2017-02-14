#ifndef ALGO_PERCOLATION_H
#define ALGO_PERCOLATION_H

#include <stdexcept>
#include <vector>

#include "UnionFind.h"

namespace algo {

namespace problems {

class Percolation {
 public:
  Percolation(std::size_t n);

  // methods
  void open(int row, int col);

  // properties

  int number_of_open_sites() const;

  bool is_open(int row, int col) const;
  bool is_full(int row, int col);
  bool percolates();

 private:
  std::size_t node_index(int row, int col) const {
    if(col < 0 || col >= grid_dimension_) throw std::runtime_error("Column index out of bounds!");

    std::size_t node = (row * grid_dimension_) + col;
    if(node >= states_.size())  throw std::runtime_error("Overflow!");
    return node;
  }

 private:
  std::vector<bool>  states_;
  std::size_t        grid_dimension_;  // number of columns in the grid
  UnionFind          uf;

  std::size_t        top_vir_idx_;
  std::size_t        bottom_vir_idx_;
};

} // namespace algo::problems

} // namespace algo

#endif //ALGO_PERCOLATION_H
