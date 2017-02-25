#include <random>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <randq.h>

class DequeTest : public testing::Test {
 public:
  DS::RandomisedQueue<int>    queue_;
};

TEST_F(DequeTest, Empty) {
  EXPECT_EQ(queue_.size(), 0);
  EXPECT_TRUE(queue_.empty());
}


TEST_F(DequeTest, UnderflowException) {
  EXPECT_THROW(queue_.dequeue(), std::out_of_range);
}

TEST_F(DequeTest, BackOperation) {
  queue_.enqueue(5);
  EXPECT_EQ(queue_.size(), 1);

  EXPECT_EQ(queue_.sample(), 5);

  queue_.emplace(10);
  EXPECT_EQ(queue_.size(), 2);

  queue_.dequeue();
  EXPECT_EQ(queue_.size(), 1);
}

TEST_F(DequeTest, FrontOperation) {
  queue_.enqueue(5);
  EXPECT_EQ(queue_.size(), 1);
  EXPECT_EQ(queue_.dequeue(), 5);

  queue_.emplace(10);
  EXPECT_EQ(queue_.size(), 1);

  queue_.dequeue();
  EXPECT_TRUE(queue_.empty());
}

TEST_F(DequeTest, Operations) {
  std::vector<int>  input(100);
  std::iota(std::begin(input), std::end(input), 1);

  std::random_device  rd;
  std::mt19937        mt(rd());
  std::shuffle(std::begin(input), std::end(input), mt);

  for(auto itr = std::begin(input); itr != std::end(input); std::advance(itr, 1)) {
    queue_.enqueue(*itr);
  }

  while(queue_.size()) {
    auto sample_value = queue_.dequeue();
    EXPECT_TRUE(std::any_of(std::begin(input), std::end(input), [=](auto i){ return i == sample_value;}));
    auto itr = queue_.iterator();
    EXPECT_TRUE(std::any_of(std::begin(input), std::end(input), [=](auto i){ return i == *itr;}));
    auto vitr = std::find(std::begin(input), std::end(input), sample_value);
    EXPECT_EQ(*vitr, sample_value);
    input.erase(vitr);
    EXPECT_EQ(input.size(), queue_.size());
  }

}
