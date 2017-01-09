#include <gtest/gtest.h>
#include "Stack.h"

TEST(TestBinaryFind, Initialisation) {
  Stack<int> stack;
}

TEST(TestBinaryFind, StackPush) {
  Stack<int> stack;
  ASSERT_TRUE(false);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
