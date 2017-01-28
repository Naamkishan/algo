#include <string>

#include <gtest/gtest.h>

#include "shunting_yard.h"

TEST(TestInfix, Expression1) {
  std::string expression("1 + ( ( 2 + 3 ) * ( 4 * 5 ) )");
  EXPECT_DOUBLE_EQ(dijkstra_infix(expression), 101);
}

TEST(TestInfix, Expression2) {
  std::string expression("( 2 * 4 ) + ( 6 - 1 )");
  EXPECT_DOUBLE_EQ(dijkstra_infix(expression), 13);
}

TEST(TestInfix, Expression3) {
  std::string expression("1 + 100 * 115 - 20 / 4");
  EXPECT_DOUBLE_EQ(dijkstra_infix(expression), 11496);
}

TEST(TestInfix, ExponentialExpression) {
  std::string expression("3 ^ 2");
  EXPECT_DOUBLE_EQ(dijkstra_infix(expression), 9);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}