#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "palindrome.h"
#include "palindrome_partitions.h"

TEST(TestPalindromes, abbc) {
  using namespace algo::problems::backtrack::palindrome;

  std::string input("abbc");
  ItrPairVec<std::string::iterator> palindromes;

  std::vector<std::string>  expected{"a", "b", "b", "bb", "c"};

  get_palindromes(input.begin(), input.end(), &palindromes);
  std::vector<std::string> result;

  for(auto& pair : palindromes) {
    result.push_back(std::string(pair.first, pair.second));
  }

  EXPECT_EQ(expected.size(), result.size());

}

TEST(TestPalindromes, geeks) {
  using namespace algo::problems::backtrack::palindrome;

  std::string input("geeks");
  ItrPairVec<std::string::iterator> palindromes;

  std::vector<std::string>  expected{"g", "e", "e", "ee", "k", "s"};

  get_palindromes(input.begin(), input.end(), &palindromes);
  std::vector<std::string> result;

  for(auto& pair : palindromes) {
    result.push_back(std::string(pair.first, pair.second));
  }

  EXPECT_EQ(expected.size(), result.size());

}

TEST(TestPalindromesPartitions, see) {
  using namespace algo::problems::backtrack::nth_palindrome;

  std::string input("see");
  StringsSet palindromes;

  StringsSet expected{Strings{"s", "e", "e"}};
  expected.insert(Strings{"s", "ee"});

  get_all_palindromes(input, &palindromes);

  EXPECT_TRUE(std::equal(expected.begin(), expected.end(), palindromes.begin()));
  EXPECT_EQ(expected.size(), palindromes.size());
}


TEST(TestPalindromesPartitions, geeks) {
  using namespace algo::problems::backtrack::nth_palindrome;

  std::string input("geeks");
  StringsSet palindromes;

  StringsSet expected{Strings{"g", "e", "e", "k", "s"}};
  expected.insert(Strings{"g", "ee", "k", "s"});

  get_all_palindromes(input, &palindromes);

  EXPECT_EQ(expected.size(), palindromes.size());
  EXPECT_TRUE(std::equal(expected.begin(), expected.end(), palindromes.begin()));

}

TEST(TestPalindromesPartitions, madam) {
  using namespace algo::problems::backtrack::nth_palindrome;

  std::string input("madam");
  StringsSet palindromes;

  StringsSet expected{Strings{"m", "a", "d", "a", "m"}};
  expected.insert(Strings{"m", "ada", "m"});
  expected.insert(Strings{"madam"});

  get_all_palindromes(input, &palindromes);

  EXPECT_TRUE(std::equal(expected.begin(), expected.end(), palindromes.begin()));
  EXPECT_EQ(expected.size(), palindromes.size());

}


int main(int argc, char** argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
