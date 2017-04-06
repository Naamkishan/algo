#include <algorithm>
#include <cstddef>
#include <vector>

#include <gtest/gtest.h>

#include "sort_cross_ref_ranges.h"

namespace TestNS {

struct Nut {
  std::size_t size_;

  Nut(std::size_t size) : size_{size} {}
  Nut(const Nut& obj) : size_{obj.size_} {}

  operator int() {return size_;}
};

struct Bolt {
  std::size_t size_;

  Bolt(std::size_t size) : size_{size} {}
  Bolt(const Nut& obj) : size_{obj.size_} {}

  operator int() {return size_;}
};

bool operator<(const Nut& nut, const Bolt& bolt) { return nut.size_ < bolt.size_; }
bool operator<(const Bolt& bolt, const Nut& nut) { return bolt.size_ < nut.size_; }


template <typename Type1, typename Type2>
struct Less;

// template specialisation
template<>
struct Less<TestNS::Nut, TestNS::Bolt> {
  bool operator()(const TestNS::Nut& nut, const TestNS::Bolt& bolt) const {
    return nut.size_ < bolt.size_;
  }
};

template<>
struct Less<TestNS::Bolt, TestNS::Nut> {
  bool operator()(const TestNS::Bolt& bolt, const TestNS::Nut& nut) const {
    return bolt.size_ < nut.size_;
  }
};


} // TestNS


TEST(TestNutsNBolts, DefaultTemplateComparatorUsed) {

  std::vector<TestNS::Nut> nuts{TestNS::Nut(5), TestNS::Nut(1), TestNS::Nut(3), TestNS::Nut(4), TestNS::Nut(2), TestNS::Nut(6)};
  std::vector<TestNS::Bolt> bolts{TestNS::Bolt(6), TestNS::Bolt(1), TestNS::Bolt(2), TestNS::Bolt(5), TestNS::Bolt(4), TestNS::Bolt(3)};

  using namespace algo::sort::problems::SortCrossRefRanges;

  sort_cross_ref_ranges(nuts.begin(), nuts.end(), bolts.begin(), bolts.end());
  EXPECT_TRUE(std::equal(nuts.begin(), nuts.end(), bolts.begin()));
}

TEST(TestNutsNBolts, ExplicitTemplateComparatorUsed) {

  TestNS::Less<TestNS::Nut, TestNS::Bolt> lessNutBolt;
  TestNS::Less<TestNS::Bolt, TestNS::Nut> lessBoltNut;

  std::vector<TestNS::Nut> nuts{TestNS::Nut(5), TestNS::Nut(1), TestNS::Nut(3), TestNS::Nut(4), TestNS::Nut(2), TestNS::Nut(6)};
  std::vector<TestNS::Bolt> bolts{TestNS::Bolt(6), TestNS::Bolt(1), TestNS::Bolt(2), TestNS::Bolt(5), TestNS::Bolt(4), TestNS::Bolt(3)};

  using namespace algo::sort::problems::SortCrossRefRanges;

  sort_cross_ref_ranges(nuts.begin(), nuts.end(), bolts.begin(), bolts.end(), lessNutBolt, lessBoltNut);
  EXPECT_TRUE(std::equal(nuts.begin(), nuts.end(), bolts.begin()));
}
