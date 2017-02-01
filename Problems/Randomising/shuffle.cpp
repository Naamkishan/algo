#include <numeric>
#include <utility>
#include <gtest/gtest.h>

#include "fisher_yates.h"

namespace {
constexpr int NUMBER = {52};
}

TEST(TestFisherYatesShuffle, SingleShuffle) {
  std::array<int, NUMBER> cards;
  std::iota(std::begin(cards), std::end(cards), 1);

  std::array<int, NUMBER> result = cards;
  algo::problems::fisher_yates_shuffle(std::begin(result), std::end(result));

  EXPECT_NE(cards, result);
}

TEST(TestFisherYatesShuffle, DoubleShuffle) {
  std::array<int, NUMBER> cards;
  std::iota(std::begin(cards), std::end(cards), 1);

  std::array<int, NUMBER> result = cards;
  algo::problems::fisher_yates_shuffle(std::begin(result), std::end(result));

  EXPECT_NE(cards, result);

  std::array<int, NUMBER> result2 = cards;
  algo::problems::fisher_yates_shuffle(std::begin(result2), std::end(result2));

  EXPECT_NE(result, result2);
}

int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
