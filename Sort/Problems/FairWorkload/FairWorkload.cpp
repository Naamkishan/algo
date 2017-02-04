#include <list>
#include <numeric>
#include <utility>
#include <vector>

#include <gtest/gtest.h>


TEST(TestFairWorkload, TwoCabinets) {
  std::list<int> expected;
  std::list<int> src;

  ASSERT_EQ(src, expected);
}

TEST(TestFairWorkload, TenCabinets) {
  std::list<int> expected;
  std::list<int> src;

  ASSERT_EQ(src, expected);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
