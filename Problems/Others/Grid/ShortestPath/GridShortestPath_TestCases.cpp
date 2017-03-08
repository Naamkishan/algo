#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "shortest_path.h"

using namespace algo::problems;

class SPTest : public testing::Test {
 public:
  SPTest() {}
};

TEST_F(SPTest, SelfConnect) {
  Grid grid(3, 3);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{2, 2}), 0);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{2, 2}), 0);
}

TEST_F(SPTest, OutOfBoundsConnect) {
  Grid grid(3, 3);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{2, 3}), std::numeric_limits<int>::max());
  EXPECT_THROW(grid.get_min_moves(Coordinates{2, 2}, Coordinates{2, 3}), std::runtime_error);
}

TEST_F(SPTest, Connect_Horz_Pos_Left_1) {
  Grid grid(3, 3);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{1, 2}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{1, 2}), 1);
}

TEST_F(SPTest, Connect_Horz_Pos_Left_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{3, 3}, Coordinates{1, 3}), 2);
}

TEST_F(SPTest, Connect_Horz_Pos_Right_1) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{2, 3}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{2, 3}), 1);
}

TEST_F(SPTest, Connect_Horz_Pos_Right_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{3, 1}, Coordinates{3, 3}), 2);
  EXPECT_EQ(grid.get_min_moves(Coordinates{3, 1}, Coordinates{3, 3}), 2);
}

TEST_F(SPTest, Connect_Horz_Pos_Down_1) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{1, 2}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{1, 2}), 1);
}

TEST_F(SPTest, Connect_Horz_Pos_Down_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{3, 3}, Coordinates{1, 3}), 2);
  EXPECT_EQ(grid.get_min_moves(Coordinates{3, 3}, Coordinates{1, 3}), 2);
}

TEST_F(SPTest, Connect_Horz_Pos_Up_1) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{3, 2}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{3, 2}), 1);
}

TEST_F(SPTest, Connect_Horz_Pos_Up_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{1, 1}, Coordinates{3, 1}), 2);
  EXPECT_EQ(grid.get_min_moves(Coordinates{1, 1}, Coordinates{3, 1}), 2);
}

TEST_F(SPTest, Connect_Diag_Pos_Down_1) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{0, 0}, Coordinates{1, 1}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{0, 0}, Coordinates{1, 1}), 1);
}

TEST_F(SPTest, Connect_Diag_Pos_Down_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{3, 3}, Coordinates{1, 1}), 2);
  EXPECT_EQ(grid.get_min_moves(Coordinates{3, 3}, Coordinates{1, 1}), 2);
}

TEST_F(SPTest, Connect_Diag_Pos_Up_1) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 2}, Coordinates{3, 3}), 1);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 2}, Coordinates{3, 3}), 1);
}

TEST_F(SPTest, Connect_Diag_Pos_Up_2) {
  Grid grid(4, 4);
  EXPECT_EQ(grid.get_num_moves(Coordinates{1, 1}, Coordinates{3, 3}), 2);
  EXPECT_EQ(grid.get_min_moves(Coordinates{1, 1}, Coordinates{3, 3}), 2);
}

TEST_F(SPTest, Connect_Diag_Point) {
  Grid grid(10, 10);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 7}, Coordinates{7, 3}), 5);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 7}, Coordinates{7, 3}), 5);
}

TEST_F(SPTest, Connect_Mixed_Point) {
  Grid grid(10, 10);
  EXPECT_EQ(grid.get_num_moves(Coordinates{2, 7}, Coordinates{4, 1}), 6);
  EXPECT_EQ(grid.get_min_moves(Coordinates{2, 7}, Coordinates{4, 1}), 6);
}

TEST_F(SPTest, Connect_Mixed_Point_2) {
  Grid grid(10, 10);
  EXPECT_EQ(grid.get_num_moves(Coordinates{7, 3}, Coordinates{4, 9}), 6);
  EXPECT_EQ(grid.get_min_moves(Coordinates{7, 3}, Coordinates{4, 9}), 6);
}


TEST_F(SPTest, Connect_Multi_Points) {
  Grid grid(10, 10);
  std::vector<Coordinates>  targets;
  targets.push_back(Coordinates{2, 2});
  targets.push_back(Coordinates{3, 3});
  targets.push_back(Coordinates{3, 4});
  targets.push_back(Coordinates{1, 4});

  int expected_moves = 5;
  EXPECT_EQ(grid.get_num_moves(Coordinates{1, 1}, targets), expected_moves);
  EXPECT_EQ(grid.get_min_moves(Coordinates{1, 1}, targets.begin(), targets.end()), expected_moves);
}
