#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(TestLinkedList, Initialisation) {
  ASSERT_NO_THROW(DS::LinkedList<int> llist);
}

#if 0
TEST(TestLinkedList, ListPushFront) {
  LinkList<int> llist;
  stack.push(10);
  ASSERT_TRUE(stack.size() == 1);
}

TEST(TestLinkedList, StackPop) {
  Stack<int> stack;
  stack.push(10);
  ASSERT_TRUE(stack.pop() == 10);
}

TEST(TestLinkedList, StackEmpty) {
  Stack<int> stack;
  ASSERT_TRUE(stack.empty());
}

#endif

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
