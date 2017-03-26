/**
 * This would use backtracking (a more efficient) for getting the list of palindrome partitions
 */
#ifndef ALGO_PALINDROME_PART_BACKTRACK_H
#define ALGO_PALINDROME_PART_BACKTRACK_H

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

namespace algo {

namespace problems {

namespace backtrack {

namespace palindrome_partition {

using Strings = std::vector<std::string>;
using StringsVector = std::vector<Strings>;

template<typename BiIter>
bool is_palindrome(BiIter begin, BiIter end) {
  auto mid = std::distance(begin, end) >> 1;

  return std::equal(begin,
                    std::next(begin, mid),
                    std::reverse_iterator<BiIter>{end});
}


template<typename BiIter>
void get_palindromes(BiIter begin, BiIter end, StringsVector* all_partitions, Strings *current_partition) {
  if(begin != end) {
    Strings& cur_part = *current_partition;

    for(auto itr{begin}; itr != end; ++itr)  {
      // debug purpose
      std::string token(begin, std::next(itr));
      if(is_palindrome(begin, std::next(itr))) {

        // add this palindrome to our list in current partition
        cur_part.push_back(std::string(begin, std::next(itr)));

        if(std::next(itr) == end) {
          // now add our list of palindromes for this sequence to the result
          (*all_partitions).push_back(cur_part);
        } else {
          // check for palindromes on the right side
          get_palindromes(std::next(itr), end, all_partitions, current_partition);
        }

        cur_part.pop_back(); // we are done with this palindrome
      }
    }
  }
}


void get_palindromes(const std::string& input, StringsVector* all_palindrome_partitions) {
  Strings current_partition;
  get_palindromes(input.begin(), input.end(), all_palindrome_partitions, &current_partition);
}


}

}

}

}


#endif //ALGO_PALINDROME_PART_BACKTRACK_H
