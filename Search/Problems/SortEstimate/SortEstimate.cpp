#include <gtest/gtest.h>
#include "SortEstimate.h"

namespace {
const double TOLERANCE = 1e-9;
}

TEST(TestSortEstimate, TestCase1) {
  int c = {1};
  int time = {8};

  const double expected_number = {4};
  double number = SortEstimate::how_many(c, time, TOLERANCE);

  EXPECT_NEAR(number, expected_number, TOLERANCE);
}


TEST(TestSortEstimate, TestCase2) {
  int c = {2};
  int time = {16};

  const double expected_number = {4.0};
  double number = SortEstimate::how_many(c, time, TOLERANCE);

  EXPECT_NEAR(number, expected_number, TOLERANCE);
}

TEST(TestSortEstimate, TestCase3) {
  int c = {37};
  int time = {12392342};

  const double expected_number = {23104.999312341137};
  double number = SortEstimate::how_many(c, time, TOLERANCE);

  EXPECT_NEAR(number, expected_number, TOLERANCE);
}


TEST(TestSortEstimate, TestCase4) {
  int c = {1};
  int time = {2000000000};

  const double expected_number = {7.637495090348122E7};
  double number = SortEstimate::how_many(c, time, TOLERANCE);

  EXPECT_NEAR(number, expected_number, TOLERANCE);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
