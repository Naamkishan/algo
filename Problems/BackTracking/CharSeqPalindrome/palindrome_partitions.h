#ifndef ALGO_PALINDROME_PARTITIONS_H
#define ALGO_PALINDROME_PARTITIONS_H

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <vector>
#include <set>

namespace algo {

namespace problems {

namespace backtrack {

namespace nth_palindrome {

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
using LookupMap = std::map<std::string, StringsSet>;


template<typename BiIter>
bool palindrome(BiIter begin, BiIter end) {
  std::reverse_iterator<BiIter> rbegin{end};

  auto mid = std::distance(begin, end) >> 1;

  return std::equal(begin, std::next(begin, mid), rbegin);
}


template<typename BiIter>
StringsSet get_palindromes(BiIter begin, BiIter end, LookupMap* lookupmap) {
  if(begin != end) {
    LookupMap& lookup = *lookupmap;
    std::string token = std::string(begin, end);

    if(lookup.find(token) != lookup.end())
      return lookup[token];

    StringsSet& all_palindromes = lookup[token];

    for(auto itr = begin; itr != end; ++itr)  {
      StringsSet left = get_palindromes(begin, itr, lookupmap);
      std::string cur_palindrome(itr, std::next(itr));
      StringsSet  right = get_palindromes(std::next(itr), end, lookupmap);

      if(!left.empty()) {
        StringsSet left_copy(left.begin(), left.end());
        left.clear();
        for(auto& palindromes : left_copy) {
          Strings pal{palindromes};
          pal.push_back(cur_palindrome);
          left.insert(pal);
        }
      } else {
        left.insert(Strings{cur_palindrome});
      }

      // now get all possible combinations
      for(auto& l : left) {
        Strings left_palindromes(l.begin(), l.end());
        if(!right.empty()) {
          for(auto& r : right) {
            Strings palindromes(left_palindromes);
            palindromes.insert(palindromes.end(), r.begin(), r.end());

            // this would automagically ignore duplicate inserts
            all_palindromes.insert(palindromes);
          }
        } else {
          all_palindromes.insert(left_palindromes);
        }
      }
    }

    if(palindrome(begin, end)) {
      all_palindromes.insert(Strings{token});
    }

    return all_palindromes;
  }

  return StringsSet();
}


std::size_t  get_all_palindromes(const std::string& input, StringsSet* all_palindromes) {

  LookupMap lookup;
  StringsSet result = get_palindromes(input.begin(), input.end(), &lookup);

  all_palindromes->insert(result.begin(), result.end());

  return all_palindromes->size();
}


} // nth_palindrome

} // backtrack

} // problems

} // algo



#endif // ALGO_PALINDROME_PARTITIONS_H