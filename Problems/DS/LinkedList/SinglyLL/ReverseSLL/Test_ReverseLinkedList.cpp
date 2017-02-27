/**
 * @brief   Contains test cases of reversal of singly linked lists
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <list>

#include "reverse_sll.h"

namespace {
const int NUMBER = 100;
}

class SLLTest : public testing::Test {
 public:
  SLLTest() : list_{nullptr} {}

 protected:
  algo::problems::LinkedList<int>*   list_;

};

TEST_F(SLLTest, Empty) {
  EXPECT_EQ(algo::problems::list_size(list_), 0);
}

TEST_F(SLLTest, ReverseEmptyList) {
  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::reverse_list(list_);

  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseOneElement) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  EXPECT_EQ(algo::problems::list_size(list_), 1);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));

  algo::problems::reverse_list(list_);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseTwoElements) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  EXPECT_EQ(algo::problems::list_size(list_), 2);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));

  algo::problems::reverse_list(list_);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseThreeElements) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(3));
  EXPECT_EQ(algo::problems::list_size(list_), 3);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));

  algo::problems::reverse_list(list_);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}


TEST_F(SLLTest, ReverseMultipleElements) {

  algo::problems::LinkedList<int>*   src{nullptr};

  for(int i = 2; i <= NUMBER; ++i) {
    // clear the lists
    algo::problems::clear_list(list_);
    algo::problems::clear_list(src);

    for(int j = 1; j < i; ++j) {
      algo::problems::add_node(list_, new algo::problems::LinkedList<int>(j));

      algo::problems::add_node(src, new algo::problems::LinkedList<int>(i - j));
    }

    EXPECT_EQ(algo::problems::list_size(list_), i - 1);
    EXPECT_EQ(algo::problems::list_size(src), i - 1);

    algo::problems::reverse_list(list_);

    EXPECT_TRUE(algo::problems::lists_equal(list_, src));
  }
}


TEST_F(SLLTest, ReverseSublist2Block3Elem) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(3));
  EXPECT_EQ(algo::problems::list_size(list_), 3);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(3));

  algo::problems::reverse_list_by_blocks(list_, 2);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseSublist2Block4Elem) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(4));
  EXPECT_EQ(algo::problems::list_size(list_), 4);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(4));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(3));

  algo::problems::reverse_list_by_blocks(list_, 2);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseSublist2Block5Elem) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(4));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(5));
  EXPECT_EQ(algo::problems::list_size(list_), 5);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(4));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(5));

  algo::problems::reverse_list_by_blocks(list_, 2);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}

TEST_F(SLLTest, ReverseSublist3Block5Elem) {
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(4));
  algo::problems::add_node(list_, new algo::problems::LinkedList<int>(5));
  EXPECT_EQ(algo::problems::list_size(list_), 5);

  algo::problems::LinkedList<int>*   src{nullptr};
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(3));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(2));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(1));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(5));
  algo::problems::add_node(src, new algo::problems::LinkedList<int>(4));

  algo::problems::reverse_list_by_blocks(list_, 3);
  EXPECT_TRUE(algo::problems::lists_equal(list_, src));
}
