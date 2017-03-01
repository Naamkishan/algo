/**
 * @brief   Contains test cases of intersecting singly linked lists
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <LinkedList.h>

#include "sll_instersect.h"

namespace {
const int NUMBER = 100;
}

class SLL_Intersect_Test : public testing::Test {
 public:
  SLL_Intersect_Test() {}

  void append_node(DS::detail::Node<int>* &head, DS::detail::Node<int>* node) {
    DS::detail::Node<int>** cur_node{&head};
    for(; *cur_node; cur_node = &(*cur_node)->next_);
    *cur_node = node;
  }

  void remove_node(DS::detail::Node<int>* &head, DS::detail::Node<int>* node) {
    for(DS::detail::Node<int>** cur_node{&head};
        *cur_node;
        cur_node = &(*cur_node)->next_) {
      if (node == *cur_node) {
        *cur_node = (*cur_node)->next_;
        return;
      }
    }
  }

  void end_list_at_node(DS::detail::Node<int>* &head, DS::detail::Node<int>* node) {
    for(DS::detail::Node<int>** cur_node{&head};
        *cur_node;
        cur_node = &(*cur_node)->next_) {
      if (node == *cur_node) {
        *cur_node = nullptr;
        return;
      }
    }
  }

  void clear(DS::detail::Node<int>* &head) {
    DS::detail::Node<int>* tmp;
    while(head) {
      tmp = head;
      head = head->next_;
      delete tmp;
    }
  }

};

TEST_F(SLL_Intersect_Test, CheckEmptyLists) {
  DS::detail::Node<int>* list1{nullptr};
  DS::detail::Node<int>* list2{nullptr};

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == pt);
}

TEST_F(SLL_Intersect_Test, CheckNonIntercepting_1Elem) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == pt);

  clear(list1);
  clear(list2);
}

TEST_F(SLL_Intersect_Test, CheckNonIntercepting) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));
  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == pt);

  clear(list1);
  clear(list2);
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_LastNode) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));

  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));

  DS::detail::Node<int>* common{new DS::detail::Node<int>(7)};
  append_node(list1, common);
  append_node(list2, common);

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == common);

  remove_node(list1, common);
  remove_node(list2, common);
  clear(list1);
  clear(list2);
  delete common;
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_FirstNode) {
  DS::detail::Node<int>* list1{nullptr};
  DS::detail::Node<int>* list2{nullptr};

  DS::detail::Node<int>* common{new DS::detail::Node<int>(7)};
  append_node(list1, common);
  append_node(list2, common);

  append_node(common, new DS::detail::Node<int>(1));
  append_node(common, new DS::detail::Node<int>(2));
  append_node(common, new DS::detail::Node<int>(3));
  append_node(common, new DS::detail::Node<int>(4));

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == common);

  clear(common);
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_SubList) {
  DS::detail::Node<int>* list1{new DS::detail::Node<int>(7)};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));

  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));
  append_node(list2, list1);

  EXPECT_TRUE(algo::problems::get_intersection_point(list1, list2) == list1);

  end_list_at_node(list2, list1);
  clear(list1);
  clear(list2);
}


TEST_F(SLL_Intersect_Test, CheckEmptyLists_Stack) {
  DS::detail::Node<int>* list1{nullptr};
  DS::detail::Node<int>* list2{nullptr};

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == pt);
}

TEST_F(SLL_Intersect_Test, CheckNonIntercepting_1Elem_Stack) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == pt);

  clear(list1);
  clear(list2);
}

TEST_F(SLL_Intersect_Test, CheckNonIntercepting_Stack) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));
  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));

  DS::detail::Node<int>* pt{nullptr};

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == pt);

  clear(list1);
  clear(list2);
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_LastNode_Stack) {
  DS::detail::Node<int>* list1{nullptr};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));

  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));

  DS::detail::Node<int>* common{new DS::detail::Node<int>(7)};
  append_node(list1, common);
  append_node(list2, common);

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == common);

  remove_node(list1, common);
  remove_node(list2, common);
  clear(list1);
  clear(list2);
  delete common;
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_FirstNode_Stack) {
  DS::detail::Node<int>* list1{nullptr};
  DS::detail::Node<int>* list2{nullptr};

  DS::detail::Node<int>* common{new DS::detail::Node<int>(7)};
  append_node(list1, common);
  append_node(list2, common);

  append_node(common, new DS::detail::Node<int>(1));
  append_node(common, new DS::detail::Node<int>(2));
  append_node(common, new DS::detail::Node<int>(3));
  append_node(common, new DS::detail::Node<int>(4));

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == common);

  clear(common);
}

TEST_F(SLL_Intersect_Test, CheckIntercepting_SubList_Stack) {
  DS::detail::Node<int>* list1{new DS::detail::Node<int>(7)};
  append_node(list1, new DS::detail::Node<int>(1));
  append_node(list1, new DS::detail::Node<int>(2));
  append_node(list1, new DS::detail::Node<int>(3));
  append_node(list1, new DS::detail::Node<int>(4));

  DS::detail::Node<int>* list2{nullptr};
  append_node(list2, new DS::detail::Node<int>(1));
  append_node(list2, new DS::detail::Node<int>(10));
  append_node(list2, new DS::detail::Node<int>(100));
  append_node(list2, new DS::detail::Node<int>(1000));
  append_node(list2, list1);

  EXPECT_TRUE(algo::problems::get_intersection_point_use_stack(list1, list2) == list1);

  end_list_at_node(list2, list1);
  clear(list1);
  clear(list2);
}