#include <gtest/gtest.h>
#include "SortEstimate.h"

TEST(TestSortEstimate, TestCase1) {
  int c = {1};
  int time = {8};

  const double expected_number = {4};
  double number = SortEstimate::how_many(c, time);

  EXPECT_TRUE(SortEstimate::is_essentially_equal(number, expected_number));
}


TEST(TestSortEstimate, TestCase2) {
  int c = {2};
  int time = {16};

  const double expected_number = {4.0};
  double number = SortEstimate::how_many(c, time);

  EXPECT_TRUE(SortEstimate::is_essentially_equal(number, expected_number));
}

TEST(TestSortEstimate, TestCase3) {
  int c = {37};
  int time = {12392342};

  const double expected_number = {23104.999312341137};
  double number = SortEstimate::how_many(c, time);

  EXPECT_TRUE(SortEstimate::is_essentially_equal(number, expected_number));
}


TEST(TestSortEstimate, TestCase4) {
  int c = {1};
  int time = {2000000000};

  const double expected_number = {7.637495090348122E7};
  double number = SortEstimate::how_many(c, time);

  EXPECT_TRUE(SortEstimate::is_essentially_equal(number, expected_number));
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
