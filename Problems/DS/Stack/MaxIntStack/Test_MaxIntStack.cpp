#include <numeric>
#include <utility>

#include <vector>

#include <gtest/gtest.h>

#include "MaxIntStack.h"


namespace {
constexpr int NUMBER{100};
}

TEST(TestStackWithMax, UnderflowCheck) {
  algo::problems::MaxIntStack stack_max;

  EXPECT_THROW(stack_max.pop(), std::out_of_range);
}

TEST(TestStackWithMax, SizeCheck) {
  for(std::size_t i{0}; i < NUMBER; ++i) {
    std::vector<int> input(i);
    std::iota(std::begin(input), std::end(input), 1);

    algo::problems::MaxIntStack stack_max;
    for (auto &elem : input) {
      stack_max.push(elem);
    }

    EXPECT_EQ(input.size(), stack_max.size());
  }
}

TEST(TestStackWithMax, OrderedSequenceMaxCheck) {
  for(std::size_t i{1}; i <= NUMBER; ++i) {
    std::vector<int> input(i);
    std::iota(std::begin(input), std::end(input), 1);

    std::vector<int>  max_values;
    algo::problems::MaxIntStack stack_max;
    for (auto &elem : input) {
      stack_max.push(elem);
      auto max = elem;
      if(!max_values.empty() &&
          (max < *std::max_element(max_values.begin(), max_values.end())))
        max = elem;
      max_values.push_back(max);
    }

    std::vector<int> result;
    while (stack_max.size()) {
      auto max = stack_max.max();
      auto from_max = max_values.back();
      EXPECT_EQ(max, from_max);
      result.emplace_back(stack_max.pop());
      max_values.pop_back();
    }

    std::reverse(input.begin(), input.end());

    EXPECT_EQ(input, result);
  }
}

TEST(TestStackWithMax, UnorderedSequenceMaxCheck) {
  for(std::size_t i{1}; i <= NUMBER; ++i) {
    std::vector<int> input(i);
    std::iota(std::begin(input), std::end(input), 1);

    std::random_shuffle(input.begin(), input.end());

    std::vector<int>  max_values;
    algo::problems::MaxIntStack stack_max;
    for (auto &elem : input) {
      stack_max.push(elem);
      auto max = elem;
      if(!max_values.empty()) {
        auto max_iter = std::max_element(max_values.begin(), max_values.end());
        if(*max_iter > max)
          max = *max_iter;
      }
      max_values.push_back(max);
    }

    std::vector<int> result;
    while (stack_max.size()) {
      auto max = stack_max.max();
      auto from_max = max_values.back();
      EXPECT_EQ(max, from_max);
      result.emplace_back(stack_max.pop());
      max_values.pop_back();
    }

    std::reverse(input.begin(), input.end());

    EXPECT_EQ(input, result);
  }
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
