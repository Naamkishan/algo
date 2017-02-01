#include <numeric>
#include <utility>
#include <gtest/gtest.h>
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"


namespace {
  constexpr int SIZE = {100};
}


TEST(TestSelectionSort, SortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  algo::sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, ReverseSortedStdArray) {
  using Array = std::array<int, 5>;
  Array src{5, 4, 3, 2, 1};
  Array expected{1, 2, 3, 4, 5};

  algo::sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedArray) {
  int src[] = {5, 3, 1, 2, 4};
  int expected[] = {1, 2, 3, 4, 5};

  algo::sort::selection_sort(std::begin(src), std::end(src));

  ASSERT_TRUE(std::equal(std::begin(src), std::end(src), expected));
}


TEST(TestInsertionSort, SortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::insertion_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestInsertionSort, ReverseSortedStdArray) {
  using Array = std::array<int, 5>;
  Array expected{1, 2, 3, 4, 5};

  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::insertion_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestInsertionSort, UnSortedArray) {
  using Array = std::array<int, 5>;
  Array expected{1, 2, 3, 4, 5};

  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::insertion_sort(std::begin(src), std::end(src));

  ASSERT_EQ(src, expected);
}

TEST(TestShellSort, SortedStdArray) {
  using Array = std::array<int, 7>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  algo::sort::shell_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestShellSort, ReverseSortedStdArray) {
  using Array = std::array<int, 5>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);

  Array src;
  std::iota(src.begin(), src.end(), 0);
  std::reverse(src.begin(), src.end());

  algo::sort::shell_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestShellSort, UnSortedArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::shell_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}


TEST(TestMergeSort, UnSortedStdArraySmall) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

  algo::sort::merge_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
