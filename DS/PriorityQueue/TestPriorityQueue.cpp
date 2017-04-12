#include <algorithm>
#include <numeric>
#include <random>
#include <stdexcept>

#include <gtest/gtest.h>

#include <utility.h>

#include "PriorityQueue.h"

namespace TestPQ {

class PQTest : public testing::Test {
 public:
  PQTest() {}

 protected:
  algo::DS::PQ::PriorityQueue<int> pq_;

};


TEST_F(PQTest, EmptyPQ) {
  EXPECT_THROW(pq_.root(), std::runtime_error);
}

TEST_F(PQTest, InsertElem) {
  pq_.enqueue(5);
  EXPECT_EQ(pq_.root(), 5);
}


TEST_F(PQTest, PopElem) {
  pq_.enqueue(5);
  EXPECT_EQ(pq_.dequeue(), 5);
  EXPECT_EQ(pq_.size(), 0);
}


TEST_F(PQTest, Heapify) {
  std::vector<int> values(5);
  std::iota(std::begin(values), std::end(values), 1);

  std::vector<int> expected(values.rbegin(), values.rend());
  Utility::shuffle(values.begin(), values.end());

  for(const auto& value : values)
    pq_.enqueue(value);

  std::vector<int> result;
  while(pq_.size()) {
    result.emplace_back(pq_.dequeue());
  }

  EXPECT_TRUE(std::equal(result.begin(), result.end(), expected.begin()));
}

} // TestPQ