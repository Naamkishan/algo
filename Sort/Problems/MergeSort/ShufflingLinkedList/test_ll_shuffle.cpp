#include <gtest/gtest.h>

#include "shuffle_linkedlist.h"

TEST(LL_Shuffle, TwoElements) {
  DS::detail::Node<int>* src{nullptr};
  append_node(src, new DS::detail::Node<int>(1));
  append_node(src, new DS::detail::Node<int>(2));

  DS::detail::Node<int>* expected{nullptr};
  append_node(expected, new DS::detail::Node<int>(2));
  append_node(expected, new DS::detail::Node<int>(1));

  algo::problems::shuffle_ll(src, 1000);
  EXPECT_TRUE(lists_equal(src, expected));

  clear_list(src);
  clear_list(expected);
}

TEST(LL_Shuffle, ThreeElements) {
  DS::detail::Node<int>* src{nullptr};
  append_node(src, new DS::detail::Node<int>(1));
  append_node(src, new DS::detail::Node<int>(2));
  append_node(src, new DS::detail::Node<int>(3));

  DS::detail::Node<int>* expected{nullptr};
  append_node(expected, new DS::detail::Node<int>(2));
  append_node(expected, new DS::detail::Node<int>(3));
  append_node(expected, new DS::detail::Node<int>(1));

  algo::problems::shuffle_ll(src, 1000);
  EXPECT_TRUE(lists_equal(src, expected));

  clear_list(src);
  clear_list(expected);
}

TEST(LL_Shuffle, FourElements) {
  DS::detail::Node<int>* src{nullptr};
  append_node(src, new DS::detail::Node<int>(1));
  append_node(src, new DS::detail::Node<int>(2));
  append_node(src, new DS::detail::Node<int>(3));
  append_node(src, new DS::detail::Node<int>(4));

  DS::detail::Node<int>* expected{nullptr};
  append_node(expected, new DS::detail::Node<int>(2));
  append_node(expected, new DS::detail::Node<int>(3));
  append_node(expected, new DS::detail::Node<int>(4));
  append_node(expected, new DS::detail::Node<int>(1));

  algo::problems::shuffle_ll(src, 1000);
  EXPECT_TRUE(lists_equal(src, expected));

  clear_list(src);
  clear_list(expected);
}

TEST(LL_Shuffle, FiveElements) {
  DS::detail::Node<int>* src{nullptr};
  append_node(src, new DS::detail::Node<int>(1));
  append_node(src, new DS::detail::Node<int>(2));
  append_node(src, new DS::detail::Node<int>(3));
  append_node(src, new DS::detail::Node<int>(4));
  append_node(src, new DS::detail::Node<int>(5));

  DS::detail::Node<int>* expected{nullptr};
  append_node(expected, new DS::detail::Node<int>(2));
  append_node(expected, new DS::detail::Node<int>(3));
  append_node(expected, new DS::detail::Node<int>(4));
  append_node(expected, new DS::detail::Node<int>(5));
  append_node(expected, new DS::detail::Node<int>(1));

  algo::problems::shuffle_ll(src, 1000);
  EXPECT_TRUE(lists_equal(src, expected));

  clear_list(src);
  clear_list(expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
