#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "palindrome_part_backtrack.h"

namespace {
using Strings = std::vector<std::string>;

struct StringsCompare{
  bool operator()(const Strings& a, const Strings& b) const {
    if(a.size() == b.size()) {
      auto length = a.size();
      for(auto i = 0; i < length; ++i) {
        if(a[i] != b[i])
          return a[i] < b[i];
      }
    }

    return (a.size() < b.size());
  }
};

using StringsSet = std::set<Strings, StringsCompare>;

}


TEST(TestPalPartBackTrack, madamimadam) {
  using namespace algo::problems::backtrack::palindrome_partition;

  std::string input("madamimadam");

  StringsVector palindromes;

  StringsSet expected{Strings{"m", "a", "d", "a", "m", "i", "m", "a", "d", "a", "m"}};
  expected.insert(Strings{"m", "ada", "m", "i", "m", "a", "d", "a", "m"});
  expected.insert(Strings{"m", "ada", "m", "i", "madam"});
  expected.insert(Strings{"m", "a", "d", "a", "mim", "a", "d", "a", "m"});
  expected.insert(Strings{"m", "a", "d", "a", "m", "i", "m", "ada", "m"});
  expected.insert(Strings{"madam", "i", "m", "ada", "m"});
  expected.insert(Strings{"madam", "i", "m", "a", "d", "a", "m"});
  expected.insert(Strings{"m", "ada", "mim", "a", "d", "a", "m"});
  expected.insert(Strings{"m", "ada", "mim", "ada", "m"});
  expected.insert(Strings{"m", "ada", "m", "i", "m", "ada", "m"});
  expected.insert(Strings{"m", "a", "d", "amima", "d", "a", "m"});
  expected.insert(Strings{"m", "a", "d", "a", "mim", "ada", "m"});
  expected.insert(Strings{"m", "a", "d", "a", "m", "i", "madam"});
  expected.insert(Strings{"m", "ada", "m", "i", "madam"});
  expected.insert(Strings{"m", "a", "damimad", "a", "m"});
  expected.insert(Strings{"madam", "i", "madam"});
  expected.insert(Strings{"m", "adamimada", "m"});
  expected.insert(Strings{"madamimadam"});

  get_palindromes(input, &palindromes);

  StringsSet actual;
  for(auto& palindrome : palindromes) {
    actual.insert(palindrome);
  }

  EXPECT_EQ(expected.size(), actual.size());
  EXPECT_TRUE(std::equal(expected.begin(), expected.end(), actual.begin()));
}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
