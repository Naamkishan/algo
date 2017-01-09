#include <gtest/gtest.h>
#include "BinarySearch.h"

TEST(TestBinaryFind, Initialisation) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
}

TEST(TestBinaryFind, PositiveSearch) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(3) == 2);
}

TEST(TestBinaryFind, PositiveSearchLeft) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(2) == 1);
}

TEST(TestBinaryFind, PositiveSearchRight) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(5) == 4);
}

TEST(TestBinaryFind, PositiveSearchFirst) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(1) == 0);
}

TEST(TestBinaryFind, PositiveSearchLast) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(6) == 5);
}

TEST(TestBinaryFind, NegativeSearch) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(0) == -1);
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}