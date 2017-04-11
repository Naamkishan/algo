#include <vector>

#include <gtest/gtest.h>

#include "nth_largest_multilist.h"


TEST(KthLargest, LinearOrder) {
  std::vector<int>  primes{2, 3, 5, 7, 11};
  std::vector<int>  squares{4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(largest_nth_element_2list_linear(primes.begin(), primes.end(), squares.begin(), squares.end(), 2), 25);
}

TEST(KthLargest, LogarithmicOrder_2) {
  std::vector<int>  primes{2, 3, 5, 7, 11};
  std::vector<int>  squares{4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 2), 25);
}

TEST(KthLargest, LogarithmicOrder_1) {
  std::vector<int>  primes{2, 3, 5, 7, 11};
  std::vector<int>  squares{4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 1), 36);
}

TEST(KthLargest, LogarithmicOrder_10) {
  std::vector<int>  primes{2, 3, 5, 7, 11};
  std::vector<int>  squares{4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 10), 2);
}

TEST(KthLargest, LogarithmicOrder_OneEmpty) {
  std::vector<int>  primes{};
  std::vector<int>  squares{1, 2, 3, 4, 9, 16, 25, 36};

  using namespace algo::problems::nth_element::multilist;

  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 8), 1);
  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 1), 36);
  EXPECT_EQ(largest_nth_element_2list_logarithmic(primes.begin(), primes.end(), squares.begin(), squares.end(), 4), 9);
}