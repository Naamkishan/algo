#include <iterator>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(TestLinkedList, Initialisation) {
  ASSERT_NO_THROW(DS::LinkedList<int> list);
}

TEST(TestLinkedList, ListEmptySize) {
  DS::LinkedList<int> list;
  ASSERT_TRUE(list.size() == 0);
  ASSERT_TRUE(list.empty());
}

TEST(TestLinkedList, ListUnderflow) {
  DS::LinkedList<int> list;
  ASSERT_TRUE(list.size() == 0);
  ASSERT_TRUE(list.empty());
  EXPECT_THROW(list.pop_front(), std::out_of_range);
}

TEST(TestLinkedList, ListPushFront) {
  DS::LinkedList<int> list;
  list.emplace_front(10);
  ASSERT_TRUE(list.size() == 1);
}

TEST(TestLinkedList, ListFront) {
  DS::LinkedList<int> list;
  list.emplace_front(10);
  ASSERT_TRUE(list.front() == 10);
}

TEST(TestLinkedList, ListPushBack) {
  DS::LinkedList<int> list;
  list.emplace_back(10);
  ASSERT_TRUE(list.size() == 1);
}

TEST(TestLinkedList, ListBack) {
  DS::LinkedList<int> list;
  list.emplace_back(10);
  ASSERT_TRUE(list.back() == 10);
}

TEST(TestLinkedList, ListFrontBack) {
  DS::LinkedList<int> list;
  list.emplace_front(10);
  ASSERT_TRUE(list.front() == 10);
  ASSERT_TRUE(list.back() == 10);
}

TEST(TestLinkedList, ListPush) {
  DS::LinkedList<int> list;
  list.emplace_back(5);
  list.emplace_front(10);

  ASSERT_TRUE(list.back() == 5);
  ASSERT_TRUE(list.front() == 10);
  ASSERT_TRUE(list.size() == 2);
}

TEST(TestLinkedList, ListPopBack) {
  DS::LinkedList<int> list;
  list.emplace_back(5);
  ASSERT_TRUE(list.back() == 5);
  list.pop_back();
  ASSERT_TRUE(list.empty());
}

TEST(TestLinkedList, ListPopFront) {
  DS::LinkedList<int> list;
  list.emplace_front(5);
  ASSERT_TRUE(list.front() == 5);
  list.pop_front();
  ASSERT_TRUE(list.empty());
}

TEST(TestLinkedList, ListMultiOpChecks) {
  DS::LinkedList<int> list;
  list.emplace_front(5);
  ASSERT_TRUE(list.front() == 5);
  list.pop_front();
  ASSERT_TRUE(list.empty());
  list.emplace_front(4);
  list.emplace_front(3);
  list.emplace_front(2);
  list.emplace_back(5);
  list.emplace_back(6);
  list.emplace_back(7);
  list.emplace_front(1);

  ASSERT_TRUE(list.front() == 1);
  ASSERT_TRUE(list.back() == 7);
  ASSERT_TRUE(list.size() == 7);
  ASSERT_TRUE(list.empty() == false);

  list.pop_back();
  ASSERT_TRUE(list.front() == 1);
  ASSERT_TRUE(list.back() == 6);
  ASSERT_TRUE(list.size() == 6);
  ASSERT_TRUE(list.empty() == false);

  list.pop_front();
  ASSERT_TRUE(list.front() == 2);
  ASSERT_TRUE(list.back() == 6);
  ASSERT_TRUE(list.size() == 5);
  ASSERT_TRUE(list.empty() == false);

  list.pop_back();
  ASSERT_TRUE(list.front() == 2);
  ASSERT_TRUE(list.back() == 5);
  ASSERT_TRUE(list.size() == 4);
  ASSERT_TRUE(list.empty() == false);

  list.emplace_front(0);
  ASSERT_TRUE(list.front() == 0);
  ASSERT_TRUE(list.back() == 5);
  ASSERT_TRUE(list.size() == 5);
  ASSERT_TRUE(list.empty() == false);

  list.pop_back();
  ASSERT_TRUE(list.front() == 0);
  ASSERT_TRUE(list.back() == 4);
  ASSERT_TRUE(list.size() == 4);
  ASSERT_TRUE(list.empty() == false);
}

TEST(TestLinkedList, ListClear) {
  DS::LinkedList<int> list;
  list.emplace_front(5);
  list.emplace_front(4);
  list.emplace_front(3);
  list.emplace_front(2);
  list.emplace_back(6);
  list.emplace_back(7);
  list.emplace_front(1);

  ASSERT_TRUE(list.size() == 7);
  ASSERT_TRUE(list.empty() == false);

  list.clear();
  ASSERT_TRUE(list.empty());
}

TEST(TestLinkedList, ListPushBackPopFront) {
  DS::LinkedList<int> list;
  list.emplace_back(5);
  list.emplace_back(4);
  list.emplace_back(3);
  list.emplace_back(2);
  list.emplace_back(1);

  ASSERT_TRUE(list.size() == 5);

  list.pop_front();
  list.pop_front();
  list.pop_front();
  list.pop_front();
  list.pop_front();

  ASSERT_TRUE(list.empty() == true);
}

TEST(TestLinkedList, CheckIterators) {

  std::vector<int> input = { 5, 4, 3, 2, 1 };

  DS::LinkedList<int> list;
  for(auto& elem : input) {
    list.push_back(elem);
  }

  ASSERT_TRUE(list.size() == 5);

  auto vitr = input.begin();
  for(auto itr = list.begin(); itr != list.end(); ++itr) {
    EXPECT_EQ(*itr, *vitr);
    ++vitr;
  }

  vitr = input.begin();
  for(auto itr = list.cbegin(); itr != list.cend(); ++itr) {
    EXPECT_EQ(*itr, *vitr);
    ++vitr;
  }

  // std::distance(list.begin(), list.end());
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
