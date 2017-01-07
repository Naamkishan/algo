#include <gtest/gtest.h>
#include "UnionFind.h"

TEST(TestUnionFind, Initialisation) {
  UnionFind uf(10);
}

TEST(TestUnionFind, CheckDisconnected) {
  UnionFind uf(10);
  ASSERT_FALSE(uf.connected(1, 2));
}

TEST(TestUnionFind, CheckUnionBasic) {
  UnionFind uf(10);
  uf.set_union(2, 3);
  ASSERT_TRUE(uf.connected(2, 3));
}

TEST(TestUnionFind, CheckUnionAll) {
  UnionFind uf(10);
  uf.set_union(2, 3);
  uf.set_union(0, 3);
  uf.set_union(6, 3);
  uf.set_union(1, 4);
  uf.set_union(9, 4);
  uf.set_union(9, 8);
  uf.set_union(8, 6);
  uf.set_union(7, 0);
  uf.set_union(1, 0);
  uf.set_union(5, 2);
  ASSERT_TRUE(uf.connected(9, 5));
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}