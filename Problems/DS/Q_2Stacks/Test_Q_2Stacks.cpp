#include <numeric>
#include <utility>

#include <vector>

#include <gtest/gtest.h>

#include "Q_2Stacks.h"

namespace {
constexpr int NUMBER{100};
}

TEST(TestQ_2Stacks, UnderflowCheck) {
  algo::problems::Q_2Stacks<int> q;

  EXPECT_THROW(q.dequeue(), std::runtime_error);
}

TEST(TestQ_2Stacks, SizeCheck) {
  for(std::size_t i{0}; i < NUMBER; ++i) {
    std::vector<int> input;
    std::iota(std::begin(input), std::end(input), 1);

    algo::problems::Q_2Stacks<int> q;
    for (auto &elem : input) {
      q.enqueue(elem);
    }

    EXPECT_EQ(input.size(), q.size());
  }
}

TEST(TestQ_2Stacks, OutputCheck) {
  for(std::size_t i{0}; i < NUMBER; ++i) {
    std::vector<int> input(i);
    std::iota(std::begin(input), std::end(input), 1);

    algo::problems::Q_2Stacks<int> q;
    for (auto &elem : input) {
      q.enqueue(elem);
    }

    std::vector<int> result;
    while (q.size()) {
      result.emplace_back(q.dequeue());
    }

    EXPECT_EQ(input, result);
  }
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
