#include <vector>
#include <random>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Permutation.h"

namespace {
const int NUMBER = {100};
}

class TestPermutation : public testing::Test {
 public:
  algo::problems::Permutation<int, std::vector>    permutation_;
};

TEST_F(TestPermutation, Empty) {
  EXPECT_EQ(permutation_.size(), 0);
  EXPECT_TRUE(permutation_.empty());
}

TEST_F(TestPermutation, SingleInput) {
  std::vector<int> input{1};
  permutation_.enqueue(std::begin(input), std::end(input));

  EXPECT_EQ(permutation_.size(), 1);
  EXPECT_FALSE(permutation_.empty());

  std::vector<int>  result(1);
  EXPECT_EQ(result.capacity(), 1);

  permutation_.permutation(1, std::begin(result));
  EXPECT_EQ(result[0], input[0]);
}

TEST_F(TestPermutation, InputRange) {
  for(std::size_t idx = 4; idx < NUMBER; idx <<= 1) {
    std::vector<int> input(idx);
    std::iota(std::begin(input), std::end(input), 1);

    std::random_device rd;
    std::mt19937 mt(rd());
    std::shuffle(std::begin(input), std::end(input), mt);

    permutation_.enqueue(std::begin(input), std::end(input));

    std::vector<int> result1(idx);
    std::vector<int> result2(idx);

    permutation_.permutation(idx - 1, result1.begin());
    permutation_.permutation(idx - 1, result2.begin());
    EXPECT_FALSE(std::equal(result1.begin(), result1.end(), result2.begin()));
  }

}
