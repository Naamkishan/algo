#include <list>
#include <numeric>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "bottom_merge_sort.h"


namespace {
  constexpr int SIZE = {8096};
}


TEST(TestSelectionSort, SortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  algo::sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size *= 2) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::selection_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestInsertionSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size *= 2) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::insertion_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestShellSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size *= 2) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::shell_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestMergeSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size *= 2) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::merge_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}

TEST(TestMergeSort, UnSortedList) {
  std::list<int> expected;
  std::list<int> src;
  for(int i = {1}; i < 10; ++i) {
    expected.push_back(i);
    src.push_front(i);
  }

  algo::sort::merge_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}


TEST(TestBottomupMergeSort, UnSortedVector) {
  constexpr int size = {10};
  std::vector<int> expected(size);
  std::iota(expected.begin(), expected.end(), 0);
  std::vector<int> src(expected);
  std::random_shuffle(src.begin(), src.end());

  algo::sort::bottom_out_merge_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
