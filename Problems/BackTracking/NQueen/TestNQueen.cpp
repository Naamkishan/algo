#include <algorithm>
#include <gtest/gtest.h>

#include "NQueen.h"



namespace {

using namespace algo::problems::backtrack::nqueen;
void generate_grid(const std::size_t dim, Grid *grid) {
  Fields fields;
  fields.resize(dim);

  (*grid).resize(dim);
  std::fill((*grid).begin(), (*grid).end(), fields);
}

}

TEST(TestNQueen, 2QUeens) {
  const std::size_t  dim{2};
  Grid  grid;
  generate_grid(dim, &grid);
  EXPECT_FALSE(n_queen_problem(&grid));
}


TEST(TestNQueen, 4QUeens) {
  const std::size_t  dim{4};
  Grid  grid;
  generate_grid(dim, &grid);
  EXPECT_TRUE(n_queen_problem(&grid));
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

