#ifndef ALGO_KTH_LARGEST_MULTILIST_H
#define ALGO_KTH_LARGEST_MULTILIST_H

#include <iterator>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <vector>

namespace algo {

namespace problems {

namespace nth_element {

namespace multilist {


#if TODO // for multiple lists
template<typename RandomIterator>
using Range = std::pair<RandomIterator, RandomIterator>;

/**
 * @brief   Find the nth element from multiple sorted lists in O(n + m)
 * @tparam RandomIterator : random iterator to the list
 * @tparam ForwardIterator : forward iterator of ListRanges
 * @tparam Comparator : should implement "less than comparator". Defaults to std::less
 * @param begin
 * @param end
 * @param comparator
 * @return
 */
template<typename RandomIterator,
    typename ForwardIterator,
    typename Comparator = std::less<typename std::iterator_traits<RandomIterator>::value_type >
>
auto nth_element_sorted(ForwardIterator begin, ForwardIterator end, Comparator comparator = Comparator()) {
  std::size_t total_elements{0};
  total_elements = std::accumulate(begin,
                                   end,
                                   0, // initial value
                                   [](std::size_t total_elements, typename std::pair<RandomIterator, RandomIterator> list_range) {
                                     return total_elements + std::distance(list_range.first, list_range.second);
                                   }
  );
}

#endif


/**
 * @brief   Finds the Nth element of the sorted lists in linear time
 * @tparam BiIterator
 * @tparam Comparator
 * @param start_1
 * @param end_1
 * @param start_2
 * @param end_2
 * @param nth_index
 * @param comparator
 * @return  the value of the nth_element
 */
template<typename BiIterator,
         typename Comparator = std::greater<typename std::iterator_traits<BiIterator>::value_type>
>
auto nth_element_2list_linear(BiIterator begin_1,
                              BiIterator end_1,
                              BiIterator begin_2,
                              BiIterator end_2,
                              std::size_t nth_index,
                              Comparator comparator = Comparator()
) {
  auto elem_idx = 0;
  std::reverse_iterator<BiIterator> nth_element;

  // convert the sequences into descending order ones
  std::reverse_iterator<BiIterator> start_1(end_1);
  std::reverse_iterator<BiIterator> finish_1(begin_1);
  std::reverse_iterator<BiIterator> start_2(end_2);
  std::reverse_iterator<BiIterator> finish_2(begin_2);

  while((start_1 != finish_1) && (start_2 != finish_2)) {
    nth_element = comparator(*start_1, *start_2) ? start_1++ : start_2++;
    if(++elem_idx == nth_index)
      break;
  }


  while((elem_idx != nth_index) && (start_1 != finish_1)) {
    nth_element = ++start_1;
  }

  while((elem_idx != nth_index) && (start_2 != finish_2)) {
    nth_element = ++start_1;
  }

  return *nth_element;
}


/**
 * @brief   Finds the Nth element of the sorted lists in logarithmic time
 * @tparam RandomIterator
 * @tparam Comparator
 * @param start_1
 * @param end_1
 * @param start_2
 * @param end_2
 * @param nth_index
 * @param comparator
 * @return  the value of the nth_element
 */
template<typename RandomIterator,
    typename Comparator = std::greater<typename std::iterator_traits<RandomIterator>::value_type>
>
auto nth_element_2list_logarithmic(RandomIterator start_1,
                                   RandomIterator end_1,
                                   RandomIterator start_2,
                                   RandomIterator end_2,
                                   std::size_t nth_index,
                                   Comparator comparator = Comparator()
) {
  --nth_index;  //  correction: our comparison is 0-based

  // converting the list from ascending to descending order
  std::reverse_iterator<RandomIterator> rstart_1(end_1);
  std::reverse_iterator<RandomIterator> rend_1(start_1);
  std::reverse_iterator<RandomIterator> rstart_2(end_2);
  std::reverse_iterator<RandomIterator> rend_2(start_2);

  // store the heads of the reversed lists
  std::reverse_iterator<RandomIterator> rhead_1{rstart_1};
  std::reverse_iterator<RandomIterator> rhead_2{rstart_2};


  auto difference = 0;

  // loop as long as both of the lists are traversable
  while((rstart_1 != rend_1) &&
      (rstart_2 != rend_2)) {

    difference = nth_index - (std::distance(rhead_1, rstart_1) + std::distance(rhead_2, rstart_2));

    if(difference > 0) { // move upwards the list (the lower range)
      if(comparator(*rstart_1, *rstart_2)) {
        std::advance(++rstart_1, std::distance(rstart_1, rend_1) >> 1);
      } else {
        std::advance(++rstart_2, std::distance(rstart_2, rend_2) >> 1);
      }
    } else if(difference < 0) { // move downwards the list (the higher range)
      if(comparator(*rstart_1, *rstart_2)) {
        // can we move
        if(rstart_2 != rhead_2)
          std::advance(--rstart_2, -std::distance(rstart_2, rend_2) >> 1);
        else
          rend_2 = rstart_2;
      } else {
        // check if we can move forward
        if(rstart_1 != rhead_1)
          std::advance(--rstart_1, -std::distance(rstart_1, rend_1) >> 1);
        else
          rend_1 = rstart_1; // we have exhausted the list
      }
    } else {
      // we got the index which points to the nth-largest element
      return comparator(*rstart_1, *rstart_2) ? *rstart_1 : *rstart_2;
    }
  }

  // one of the lists have exhausted
  std::reverse_iterator<RandomIterator> active = (rstart_1 != rend_1) ? rstart_1 : rstart_2; // there are only two lists .. so checking emptiness for one should suffice

  difference = nth_index - (std::distance(rhead_1, rstart_1) + std::distance(rhead_2, rstart_2));

  return *std::next(active, difference);
}


} // algo::problems::nth_element::multilist

} // algo::problems::nth_element

} // algo::problems

} // algo

#endif //ALGO_KTH_LARGEST_MULTILIST_H
