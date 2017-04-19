/**
 * This translation unit contains all the test cases for DynamicMedian
 */

#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>

#include <gtest/gtest.h>

#include "dyanmic_median.h"



class TestDynamicMedian : public testing::Test {
 public:
  TestDynamicMedian() {}

 protected:
  algo::problems::DS::PriorityQueue::DynamicMedian<int, float>  dynamic_median_;

};


TEST_F(TestDynamicMedian, Empty) {
  using namespace algo::problems::DS::PriorityQueue;

  EXPECT_TRUE(dynamic_median_.empty());
}

TEST_F(TestDynamicMedian, EmptyMedian) {
  using namespace algo::problems::DS::PriorityQueue;

  EXPECT_THROW(dynamic_median_.median(), std::range_error);
}

TEST_F(TestDynamicMedian, Median_1) {
  using namespace algo::problems::DS::PriorityQueue;

  int value{1};
  dynamic_median_.enqueue(value);
  float median = dynamic_median_.median();
  EXPECT_EQ(median, static_cast<float>(value));
}

TEST_F(TestDynamicMedian, Median_2) {
  using namespace algo::problems::DS::PriorityQueue;

  float median, sum;
  std::vector<int> values;

  for(int value{1}; value <= 2; ++value) {
    values.push_back(value);
    dynamic_median_.enqueue(value);

    median = dynamic_median_.median();
    sum = std::accumulate(values.begin(), values.end(), 0.0);
    EXPECT_EQ(median, static_cast<float>(sum/values.size()));
  }

}

TEST_F(TestDynamicMedian, Median_Multi) {
  using namespace algo::problems::DS::PriorityQueue;

  float median, expected;
  std::size_t  mid;
  std::vector<int> values;

  for(int value{3}; value <= 25; ++value) {
    values.push_back(value);
    dynamic_median_.enqueue(value);

    median = dynamic_median_.median();
    mid = values.size() >> 1;
    if(values.size() & 1) {
      expected = values[mid];
    } else {
       expected = (static_cast<float>(values[mid] + values[mid - 1]))/2;
    }

    EXPECT_EQ(median, expected);
  }
}
