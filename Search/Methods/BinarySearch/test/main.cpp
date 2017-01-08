#include <gtest/gtest.h>
#include "BinarySearch.h"

TEST(TestBinaryFind, Initialisation) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
}

TEST(TestBinaryFind, PositiveSearch) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_TRUE(bs.find(3));
}

TEST(TestBinaryFind, NegativeSearch) {
  int values[] = {1, 2, 3, 4, 5, 6};
  BinarySearch<int> bs(values);
  ASSERT_FALSE(bs.find(0));
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}