#include <gtest/gtest.h>
#include "Stack.h"

TEST(TestStack, Initialisation) {
  ASSERT_NO_THROW(Stack<int> stack);
}

TEST(TestStack, StackPush) {
  Stack<int> stack;
  stack.push(10);
  ASSERT_TRUE(stack.size() == 1);
}

TEST(TestStack, StackPop) {
  Stack<int> stack;
  stack.push(10);
  ASSERT_TRUE(stack.pop() == 10);
}

TEST(TestStack, StackEmpty) {
  Stack<int> stack;
  ASSERT_TRUE(stack.empty());
}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
