#include <numeric>
#include <random>
#include <gtest/gtest.h>
#include "merge_sorted_aux.h"

using namespace algo::problems;

namespace {
constexpr int SIZE = {111111};

template<typename ForwardIterator>
void randomise(ForwardIterator begin, ForwardIterator end) {
  std::random_device rd;
  std::mt19937 rnd_eng(rd());
  std::shuffle(begin, end, rnd_eng);
}

template<typename ForwardIterator>
void sort(ForwardIterator begin, ForwardIterator end) {
  std::sort(begin, end);
}

}

TEST(TestMergeSmallerAux, TwoElementArray) {
  using Array = std::array<int, 2>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  merge_sorted_aux(src._M_elems);

  ASSERT_EQ(src, expected);
}

TEST(TestMergeSmallerAux, LargeArray) {
  constexpr int partition = SIZE >> 1;
  using Array = std::array<int, SIZE>;
  Array expected;
  std::iota(expected.begin(), expected.end(), 0);
  Array src = expected;

  // randomise the array
  randomise(src.begin(), src.end());
  // sort the elements half way
  sort(src.begin(), std::next(src.begin(), partition));
  sort(std::next(src.begin(), partition), src.end());
  merge_sorted_aux(src._M_elems);

  ASSERT_EQ(src, expected);
}
