#include <utility>
#include <gtest/gtest.h>
#include "selection_sort.h"
#include "insertion_sort.h"

TEST(TestSelectionSort, SortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{1, 2, 3, 4, 5};
  Array expected{1, 2, 3, 4, 5};

  sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{5, 3, 1, 2, 4};
  Array expected{1, 2, 3, 4, 5};

  sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, ReverseSortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{5, 4, 3, 2, 1};
  Array expected{1, 2, 3, 4, 5};

  sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedArray) {
  int src[] = {5, 3, 1, 2, 4};
  int expected[] = {1, 2, 3, 4, 5};

  sort::selection_sort(std::begin(src), std::end(src));

  ASSERT_TRUE(std::equal(std::begin(src), std::end(src), expected));
}


TEST(TestInsertionSort, SortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{1, 2, 3, 4, 5};
  Array expected{1, 2, 3, 4, 5};

  sort::insertion_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestInsertionSort, ReverseSortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{5, 4, 3, 2, 1};
  Array expected{1, 2, 3, 4, 5};

  sort::insertion_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestInsertionSort, UnSortedArray) {
  int src[] = {5, 3, 1, 2, 4};
  int expected[] = {1, 2, 3, 4, 5};

  int end_itr = sizeof(src)/sizeof(int);

  sort::insertion_sort(src, src + end_itr);

  ASSERT_TRUE(std::equal(src, src + end_itr, expected));
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
