#include <functional>
#include <vector>

#include <gtest/gtest.h>

#include "partition_keys.h"

TEST(DecimalDominants, AllEvenList) {
  using IntVector = std::vector<int>;
  IntVector evens{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};

  IntVector expected{10, 20};

  using namespace algo::problems::partition;
  auto top = partition_range_by_predicate(evens.begin(),
                                          evens.end(),
                                          [](auto x) {
                                            return x % 10 == 0;
                                          }
  );

  IntVector result(evens.begin(), top);
  std::sort(result.begin(), result.end());

  EXPECT_TRUE(std::equal(result.begin(), result.end(), expected.begin()));
}

TEST(DecimalDominants, AllPass) {
  using IntVector = std::vector<int>;
  IntVector values{10, 20, 30, 40, 50, 60, 70, 80};

  IntVector expected(values.begin(), values.end());

  using namespace algo::problems::partition;
  auto top = partition_range_by_predicate(values.begin(),
                                          values.end(),
                                          [](auto x) {
                                            return x % 10 == 0;
                                          }
  );

  EXPECT_TRUE(std::equal(values.begin(), top, expected.begin()));
}