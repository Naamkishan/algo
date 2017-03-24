#ifndef ALGO_PALINDROME_H
#define ALGO_PALINDROME_H

#include <cstddef>
#include <iterator>
#include <set>

namespace algo {

namespace problems {

namespace backtrack {

namespace palindrome {

/**
 * function to be used by std::map for looking up
 * @param a : std::pair<Iterator>
 * @param b : std::pair<Iterator>
 * @return true if a < b else false
 */
template<typename Iterator>
struct ItrPairCmp {
  bool operator()(const std::pair<Iterator, Iterator>& a, const std::pair<Iterator, Iterator>& b) const {
    if(a.first == b.first)
      return a.second < b.second;
    return (a.first < b.first);
  }

};

template<typename Iterator>
using ItrPairSet = std::set<typename std::pair<Iterator, Iterator>, ItrPairCmp<Iterator> >;


template<typename Iterator>
using ItrPairVec = std::vector<typename std::pair<Iterator, Iterator> >;


/**
 * @brief   checks if the given sequence is a palindrome or not
 * @param begin : start of range
 * @param end : end of range (past the last element)
 * @return  true if palindrome; empty string is also reported as palindrome
 */
template<typename RandomIterator>
bool is_palindrome(RandomIterator begin, RandomIterator end) {
  if(begin != end) {
    --end;  // bring end to the last element of the range
    while(begin != end) {
      if(*begin != *end)
        return false;

      // check for cross-overs .. this will be true for even numbered range
      if(++begin == end)
        break;

      --end;
    }
  }
  return true;
}

/**
 * get_palindromes : gets the number of possible of palindromes from the provided range
 * @param begin
 * @param end
 * @param visited
 * @param result  : the number of palindromes found
 */
template<typename RandomIterator>
void get_palindromes(RandomIterator begin,   // start of range
                     RandomIterator end,     // end of range
                     ItrPairSet<RandomIterator>* visited,
                     ItrPairVec<RandomIterator>* result) {  // the list of palindromes to be stored in
  if(begin != end) {
    auto found = (*visited).find(std::make_pair(begin, end));
    if(found == (*visited).end()) {
      if(is_palindrome(begin, end)) {
        // add to the result if its a palindrome
        (*result).push_back(std::make_pair(begin, end));
      }

      // mark this range has been visited
      (*visited).insert(std::make_pair(begin, end));

      // look for possible subsets of palindromes
      for(auto itr = begin; itr != end; ++itr) {
        get_palindromes(begin, itr, visited, result);
        get_palindromes(itr, end, visited, result);
      }

    }
  }
}

/**
 * get_palindromes : gets the number of possible of palindromes from the provided range
 * @param begin
 * @param end
 * @param result  : the number of palindromes found\
 * @return  the number of palindromes found
 */
template<typename RandomIterator>
std::size_t get_palindromes(RandomIterator begin,   // start of range
                            RandomIterator end,     // end of range
                            ItrPairVec<RandomIterator>* palindromes) {  // the list of palindromes to be stored in
  ItrPairSet<RandomIterator>  visited;
  if(begin != end) {
    get_palindromes(begin, end, &visited, palindromes);
  }

  return (*palindromes).size();
}

} // namespace algo::problems::backtrack::palindrome

} // namespace algo::problems::backtrack

} // namespace algo::problems

} // namespace algo


#endif //ALGO_PALINDROME_H
