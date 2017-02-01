#include <numeric>
#include <utility>
#include <gtest/gtest.h>

namespace {
constexpr int VERTICES = {10};
}

TEST(TestFisherYatesShuffle, SingleShuffle) {
  std::array<int, VERTICES> points;
  std::iota(std::begin(points), std::end(points), 1);

  std::array<int, VERTICES> result = points;

  EXPECT_EQ(points, result);
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

