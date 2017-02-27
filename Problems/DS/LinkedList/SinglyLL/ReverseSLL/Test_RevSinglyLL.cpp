#include <numeric>
#include <utility>

#include <vector>

#include <gtest/gtest.h>


namespace {
constexpr int NUMBER{100};
}

int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
