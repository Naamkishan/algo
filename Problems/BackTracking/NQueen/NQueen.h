#ifndef ALGO_NQUEEN_H
#define ALGO_NQUEEN_H

#include <algorithm>
#include <climits>
#include <cstddef>

namespace {
constexpr const int CELL_AVAILABLE{-1};
constexpr const int CELL_ACQUIRED{0};
constexpr const int QUEEN{1};

}

namespace algo {

namespace problems {

namespace backtrack {

namespace nqueen {

using Fields = std::vector<int>;
using Grid = std::vector<Fields>;

void reset_grid(Grid* grid, const int def_value = CELL_AVAILABLE) {
  for(auto& fields : *grid) {
    std::fill(fields.begin(), fields.end(), def_value);
  }
}


bool acquire(int row, int col, Grid* grid) {
  Grid& workspace = *grid;
  if(workspace[row][col] == CELL_AVAILABLE) {
    int diagonal_offset; // used for acquiring the diagnoal cells
    auto rows = workspace.size();
    int left_col,   // column index for left cell of diagonal
        right_col;  // column index for right cell of the diagonal
    for(auto itr = 0; itr < rows; ++itr) {
      workspace[itr][col] = CELL_ACQUIRED;  // the vertical column for this idx = col is acquired
      workspace[row][itr] = CELL_ACQUIRED;  // the horizontal row for this idx = row is acquire

      diagonal_offset = row - itr;
      left_col = col - diagonal_offset;  // roles get reversed if diagonal_offset is -ve
      right_col = col + diagonal_offset;
      if((left_col >= 0) and (left_col < rows)) {
        workspace[itr][left_col] = CELL_ACQUIRED;
      }
      if((right_col >= 0) and (right_col < rows)) {
        workspace[itr][right_col] = CELL_ACQUIRED;
      }
    }

    // this position is now taken
    workspace[row][col] = QUEEN;

    return true;
  }

  return false;
}

bool try_fill(int row, int col, Grid* grid) {
  Grid& workspace = *grid;

  if(!acquire(row, col, grid))
    return false;

  bool available{false};  // flag to indicate that queen can be placed

  for(auto i = 0; i < workspace[0].size(); ++i) {
    // all the corresponding columns of the row has been acquired
    if(row == i)    continue;

    for(auto j = 0; j < workspace[i].size() && !available; ++j) {
      // all the cells for every row this this column has been taken
      if(j == col)  continue;
      available = acquire(i, j, grid);
    }
    // for this row not even a single cell could be found suitable for queen
    if(!available)
      return false;

    // reset flag. Check availability for next row
    available = false;
  }

  return true;
}

/**
 * @brief Finds a possible solution for placing a Queen on each row of a NxN grid
 * @param grid (the actual grid on which the queens are to be placed.
 * @return  true if a solution is found else false
 */
bool n_queen_problem(Grid* grid) {
  Grid& workspace = *grid;
  auto dimensions = workspace.size();

  // try to get all possible combinations to fill the N queues. Break on the first successful combo
  for(auto i = 0; i < dimensions; ++i) {
    for(auto j = 0; j < dimensions; ++j) {
      // reset the grid
      reset_grid(grid);
      if(try_fill(i, j, grid)) {
        return true;
      }
    }
  }

  return false;
}


}

}

}

}

#endif //ALGO_NQUEEN_H
