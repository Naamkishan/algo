#include <numeric>
#include <utility>
#include <gtest/gtest.h>

namespace {
  constexpr int SIZE = {100};
}

TEST(TestSelectionSort, SortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  sort::selection_sort(src.begin(), src.end());

  ASSERT_EQ(src, expected);
}

TEST(TestSelectionSort, UnSortedStdArray) {
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;
  std::random_shuffle(src.begin(), src.end());

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


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
