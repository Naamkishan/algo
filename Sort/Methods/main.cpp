#include <list>
#include <numeric>
#include <utility>
#include <vector>

#include <gtest/gtest.h>
#include <utility.h>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "bottom_merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "qsort_3way.h"
#include "heap_sort.h"

namespace {
  constexpr int SIZE = {8095};
}


TEST(TestBubbleSort, SortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  algo::sort::bubble_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestBubbleSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::bubble_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestInsertionSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::insertion_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestShellSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    std::random_shuffle(src.begin(), src.end());

    algo::sort::shell_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestMergeSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
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
  for(int i = {1}; i < 8095; ++i) {
    expected.push_back(i);
    src.push_front(i);
  }

  algo::sort::merge_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestBottomupMergeSort, UnSortedList) {
  std::list<int> expected;
  std::list<int> src;
  for(int i = {1}; i < 8095; ++i) {
    expected.push_back(i);
    src.push_front(i);
  }

  algo::sort::bottom_out_merge_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestBottomupMergeSort, UnSortedMultiVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::bottom_out_merge_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}

TEST(TestQuickSort, UnSortedMultiVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::quick_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}

TEST(Test3WayQuickSort, UnSortedMultiVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::quicksort_3way(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestStdQuickSort, UnSortedMultiVectors) {
  for(std::size_t size = {1}; size < SIZE; size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::using_std::quick_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


TEST(TestBottomupMergeSort, UnSorted1Million) {
    std::vector<int> expected(1000000);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::bottom_out_merge_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
}

TEST(TestQuickSort, UnSorted1Million) {
    std::vector<int> expected(1000000);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

    algo::sort::quick_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
}

TEST(Test3WayQuickSort, UnSorted1Million) {
  std::vector<int> expected(1000000);
  std::iota(expected.begin(), expected.end(), 0);
  std::vector<int> src(expected);
  std::random_shuffle(src.begin(), src.end());

  algo::sort::quicksort_3way(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}


TEST(TestStdQuickSort, UnSorted1Million) {
  std::vector<int> expected(1000000);
  std::iota(expected.begin(), expected.end(), 0);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  algo::sort::using_std::quick_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}



TEST(TestSelectionSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < (SIZE >> 2); size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::selection_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}

TEST(DISABLED_TestStdSelectionSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < (SIZE >> 2); size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::using_std::selection_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}

/**
 * Test 3 way quick sort with 4 duplicate keys
 */
TEST(Test3WayQuickSort, UnSortedMultipleVectors_Duplicates) {
  const int million{1000000};
  std::vector<int> expected(million);
  for(auto i = 0; i < million; i += 4)
    std::iota(std::next(expected.begin(), i), std::next(expected.begin(), i + 4), i);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::quicksort_3way(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

/**
 * Test 3 way quick sort with 4 duplicate keys
 */
TEST(TestQuickSort, UnSortedMultipleVectors_Duplicates) {
  const int million{1000000};
  std::vector<int> expected(million);
  for(auto i = 0; i < million; i += 4)
    std::iota(std::next(expected.begin(), i), std::next(expected.begin(), i + 4), i);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::quick_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

/**
 * Test 3 way quick sort with 4 duplicate keys
 */
TEST(TestStdQuickSort, UnSortedMultipleVectors_Duplicates) {
  const int million{1000000};
  std::vector<int> expected(million);
  for(auto i = 0; i < million; i += 4)
    std::iota(std::next(expected.begin(), i), std::next(expected.begin(), i + 4), i);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::using_std::quick_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

/**
 * Test 3 way quick sort with ALL duplicate keys
 */
TEST(Test3WayQuickSort, UnSortedMultipleVectors_AllDuplicates) {
  const int thousands{10000};
  std::vector<int> expected(thousands);
  std::fill(expected.begin(), expected.end(), 1);

  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::quicksort_3way(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

/**
 * Test 3 way quick sort with ALL duplicate keys
 */
TEST(TestQuickSort, UnSortedMultipleVectors_AllDuplicates) {
  const int thousands{10000};
  std::vector<int> expected(thousands);
  std::fill(expected.begin(), expected.end(), 1);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::quick_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

/**
 * Test 3 way quick sort with ALL duplicate keys
 */
TEST(TestStdQuickSort, UnSortedMultipleVectors_AllDuplicates) {
  const int thousands{10000};
  std::vector<int> expected(thousands);
  std::fill(expected.begin(), expected.end(), 1);
  std::vector<int> src(expected);
  Utility::shuffle(src.begin(), src.end());

  std::sort(expected.begin(), expected.end());
  algo::sort::using_std::quick_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}



/**
 * Test Heap Sort
 */
TEST(TestHeapSort, UnSortedMultipleVectors) {
  for(std::size_t size = {1}; size < (SIZE >> 2); size <<= 1) {
    std::vector<int> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int> src(expected);
    Utility::shuffle(src.begin(), src.end());

    algo::sort::binary_heap::heap_sort(src.begin(), src.end());

    ASSERT_EQ(src, expected);
  }
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
