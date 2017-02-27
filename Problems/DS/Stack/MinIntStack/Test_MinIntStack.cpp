#include <numeric>
#include <utility>

#include <vector>

#include <gtest/gtest.h>

#include "MinIntStack.h"

namespace {
constexpr int NUMBER{100};
}


TEST(Test_MinIntStack, UnderflowCheck) {
  algo::problems::MinIntStack min_stack;

  EXPECT_THROW(min_stack.pop(), std::out_of_range);
}


TEST(Test_MinIntStack, SizeCheck) {
  for(std::size_t i{0}; i < NUMBER; ++i) {
    std::vector<int> input;
    std::iota(std::begin(input), std::end(input), 1);

    algo::problems::MinIntStack min_stack;
    for (auto &elem : input) {
      min_stack.push(elem);
    }

    EXPECT_EQ(input.size(), min_stack.size());
  }
}

TEST(Test_MinIntStack, UnorderedSequenceMaxCheck) {
  for(std::size_t i{1}; i <= NUMBER; ++i) {
    std::vector<int> input(i);
    std::iota(std::begin(input), std::end(input), 1);

    std::random_shuffle(input.begin(), input.end());

    std::vector<int>  stack_values;
    algo::problems::MinIntStack min_stack;
    for (auto &elem : input) {
      min_stack.push(elem);
      stack_values.push_back(elem);
    }

    std::vector<int> result;
    while (min_stack.size()) {
      auto min_from_stack = min_stack.min();
      auto min_iter = std::min_element(stack_values.begin(), stack_values.end());
      EXPECT_EQ(*min_iter, min_from_stack);
      result.emplace_back(min_stack.pop());
      stack_values.pop_back();
    }

    std::reverse(input.begin(), input.end());

    EXPECT_EQ(input, result);
  }
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
