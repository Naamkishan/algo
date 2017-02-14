#include "percolation.h"

#include <numeric>
#include <stdexcept>

namespace algo {

namespace problems {

/**
 * @brief   Create a "n x n" grid in constructor
 * @param n     Number or row and column elements
 */
Percolation::Percolation(std::size_t n) : states_(n * n, false),
                                          grid_dimension_{n},
                                          uf((n * n) + 2) {  // additional 2 cells - used for checking percolation
  // reserving the penultimate cell in UnionFind to be the virtual cell which will connect to all the cells in the top row
  top_vir_idx_ = grid_dimension_ * grid_dimension_;
  // reserving the last cell in UnionFind to be the virtual cell which will connect to all the cells in the bottom row
  bottom_vir_idx_ = (grid_dimension_ * grid_dimension_) + 1; // the index is 0-based
}
/**
 * @brief   returns the number of open sites
 * @return  int
 */
int Percolation::number_of_open_sites() const {
  auto is_open_state = [&](int value, bool state) { if(state) ++value; return value; };
  return std::accumulate(states_.begin(), states_.end(), 0, is_open_state);
}

/**
 * @brief   checks if the given grid cell is open
 * @param row
 * @param col
 * @return  boolean
 */
bool Percolation::is_open(int row, int col) const {
  return states_[node_index(row, col)];
}

/**
 * @brief   checks if the current cell is connected from the top
 * @param row
 * @param col
 * @return boolean
 */
bool Percolation::is_full(int row, int col) {
  return uf.connected(top_vir_idx_, node_index(row, col));
}

/**
 * @brief   Checks if the system percolates
 * @return  boolean
 */
bool Percolation::percolates() {
  return uf.connected(top_vir_idx_, bottom_vir_idx_);  // adjustment for 0-based index
}

/**
 * @brief   Open a site if already not opened. Ensure it gets connected to its neighbours
 * @param row
 * @param col
 */
void Percolation::open(int row, int col) {
  if(is_open(row, col))     return;

  auto cur_cell_idx = node_index(row, col);

  // connect with neighbouring cells (if they are already open)

  // row-wise

  if(row == 0) { // if the top most row .. then connect with virtual top cell
    uf.set_union(cur_cell_idx, top_vir_idx_);
  } else if(is_open(row - 1, col)) { // connect to the immediate above cell if open
      uf.set_union(cur_cell_idx, node_index(row - 1, col));
  }

  if(row == (grid_dimension_ - 1)) { // if the bottom most row .. then connect with virtual bottom cell
    uf.set_union(cur_cell_idx, bottom_vir_idx_);
  } else if(is_open(row + 1, col)){ // connect to the immediately below cell if open
    uf.set_union(cur_cell_idx, node_index(row + 1, col));
  }

  // column-wise
  // connect to the left cell
  if((col > 0) && is_open(row, col - 1)) {
    uf.set_union(node_index(row, col), node_index(row, col - 1));
  }
  // connect to the right cell
  if((col < (grid_dimension_ - 1)) && is_open(row, col + 1)) {
    uf.set_union(node_index(row, col), node_index(row, col + 1));
  }

  states_[node_index(row, col)] = true;
}


} // namespace algo::problems

} // namespace algo
