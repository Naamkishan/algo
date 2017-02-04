#include <list>
#include <numeric>
#include <utility>
#include <vector>

#include <gtest/gtest.h>
#include "FairWorkload.h"

TEST(TestFairWorkload, Cabs1Wokers1) {
  std::array<int, 2> cabinets = { 1, 1 };
  const int workers = 1;

  const int max_cabs_per_worker = {2};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}


TEST(TestFairWorkload, Cabs9Wokers3) {
  std::array<int, 9> cabinets = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  const int workers = 3;

  const int max_cabs_per_worker = {170};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

TEST(TestFairWorkload, Cabs9Wokers5) {
  int cabinets[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  const int workers = 5;

  const int max_cabs_per_worker = {110};
  const int act_cabs_per_worker = get_most_work(std::begin(cabinets), std::end(cabinets), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}


TEST(TestFairWorkload, Cabs15Wokers4) {
  std::vector<int> cabinets = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
  const int workers = 4;

  const int max_cabs_per_worker = {1785};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

TEST(TestFairWorkload, Cabs7Wokers2) {
  std::array<int, 7> cabinets = { 50, 50, 50, 50, 50, 50, 50 };
  const int workers = 2;

  const int max_cabs_per_worker = {200};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

TEST(TestFairWorkload, Cabs15Wokers2) {
  std::array<int, 15> cabinets = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
  const int workers = 2;

  const int max_cabs_per_worker = {1000};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

TEST(TestFairWorkload, Cabs5Wokers5) {
  std::array<int, 15> cabinets = { 1, 1, 1, 1, 100 };
  const int workers = 5;

  const int max_cabs_per_worker = {100};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

TEST(TestFairWorkload, Cabs10Wokers5) {
  std::array<int, 10> cabinets = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
  const int workers = 5;

  const int max_cabs_per_worker = {950};
  const int act_cabs_per_worker = get_most_work(cabinets.begin(), cabinets.end(), workers);

  ASSERT_EQ(max_cabs_per_worker, act_cabs_per_worker);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
