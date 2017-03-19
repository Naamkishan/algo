#include <numeric>
#include <utility>
#include <gtest/gtest.h>

namespace {
constexpr int VERTICES = {10};
}

int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

