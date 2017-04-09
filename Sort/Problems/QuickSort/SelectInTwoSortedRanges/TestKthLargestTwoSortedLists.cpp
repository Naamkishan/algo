#include <vector>

#include <gtest/gtest.h>

#include "kth_largest_multilist.h"


TEST(KthLargest, LinearOrder) {
  std::vector<int>  primes{2, 3, 5, 7, 11};
  std::vector<int>  squares{4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(nth_element_2list_linear(primes.begin(), primes.end(), squares.begin(), squares.end(), 4), 5);
}