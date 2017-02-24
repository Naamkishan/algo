#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Deque.h>

class DequeTest : public testing::Test {
 public:
  DS::Deque<int>    deque_;
};

TEST_F(DequeTest, UnderflowException) {
  EXPECT_THROW(deque_.pop_back(), std::out_of_range);
}

TEST_F(DequeTest, BackOperation) {
  deque_.push_back(5);
  EXPECT_EQ(deque_.size(), 1);

  deque_.emplace_back(10);
  EXPECT_EQ(deque_.size(), 2);

  EXPECT_EQ(deque_.pop_back(), 10);
  EXPECT_EQ(deque_.size(), 1);
}

TEST_F(DequeTest, FrontOperation) {
  deque_.push_front(5);
  EXPECT_EQ(deque_.size(), 1);

  deque_.emplace_front(10);
  EXPECT_EQ(deque_.size(), 2);

  EXPECT_EQ(deque_.pop_front(), 10);
  EXPECT_EQ(deque_.size(), 1);

  EXPECT_EQ(deque_.pop_front(), 5);
  EXPECT_TRUE(deque_.empty());
}

TEST_F(DequeTest, Operations) {
  deque_.push_front(5);
  EXPECT_EQ(deque_.size(), 1);

  deque_.emplace_front(10);
  EXPECT_EQ(deque_.size(), 2);

  deque_.push_back(15);
  EXPECT_EQ(deque_.size(), 3);

  EXPECT_EQ(deque_.pop_front(), 10);
  EXPECT_EQ(deque_.size(), 2);

  EXPECT_EQ(deque_.pop_back(), 15);
  EXPECT_EQ(deque_.size(), 1);

  EXPECT_EQ(deque_.pop_front(), 5);
  EXPECT_TRUE(deque_.empty());
}
