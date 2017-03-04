#include <array>
#include <iterator>
#include <vector>
#include <gtest/gtest.h>

#include "count_inversion.h"

namespace {
std::array<int, 5> aux;
}

TEST(CountInversions_STL, OneInversion) {
  int array[] = {2, 1, 3, 4, 5};

  EXPECT_EQ(algo::problems::count_inversion_stl(array), 1);
}

TEST(CountInversions_STL, TwoInversions) {
  int array[] = {2, 3, 1, 4, 5};

  EXPECT_EQ(algo::problems::count_inversion_stl(array), 2);
}

TEST(CountInversions_STL, ThreeInversions) {
  int array[] = {2, 4, 1, 3, 5};

  EXPECT_EQ(algo::problems::count_inversion_stl(array), 3);
}

TEST(CountInversions_STL, SixInversions) {
  int array[] = {8, 4, 2, 1};

  EXPECT_EQ(algo::problems::count_inversion_stl(array), 6);
}

TEST(CountInversions_MS, OneInversion) {
  int array[] = {2, 1, 3, 4, 5};

  EXPECT_EQ(algo::problems::merge_sort_with_inv_count(std::begin(array), std::end(array), std::begin(aux)), 1);
}

TEST(CountInversions_MS, TwoInversions) {
  int array[] = {2, 3, 1, 4, 5};

  EXPECT_EQ(algo::problems::merge_sort_with_inv_count(std::begin(array), std::end(array), std::begin(aux)), 2);
}

TEST(CountInversions_MS, ThreeInversions) {
  int array[] = {2, 4, 1, 3, 5};

  EXPECT_EQ(algo::problems::merge_sort_with_inv_count(std::begin(array), std::end(array), std::begin(aux)), 3);
}

TEST(CountInversions_MS, SixInversions) {
  int array[] = {8, 4, 2, 1};

  EXPECT_EQ(algo::problems::merge_sort_with_inv_count(std::begin(array), std::end(array), std::begin(aux)), 6);
}
