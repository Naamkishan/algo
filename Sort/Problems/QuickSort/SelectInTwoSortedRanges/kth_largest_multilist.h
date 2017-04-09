#ifndef ALGO_KTH_LARGEST_MULTILIST_H
#define ALGO_KTH_LARGEST_MULTILIST_H

#include <iterator>
#include <numeric>
#include <utility>
#include <vector>

namespace algo {

namespace problems {

namespace nth_element {

namespace multilist {


#if 0
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


/**
 * @brief   Finds the Nth element of the sorted lists in logarithmic time
 * @tparam ForwardIterator
 * @tparam Comparator
 * @param start_1
 * @param end_1
 * @param start_2
 * @param end_2
 * @param nth_index
 * @param comparator
 * @return  the value of the nth_element
 */
template<typename ForwardIterator,
    typename Comparator = std::less<typename std::iterator_traits<ForwardIterator>::value_type>
>
auto nth_element_2list_logarithmic(ForwardIterator start_1,
                              ForwardIterator end_1,
                              ForwardIterator start_2,
                              ForwardIterator end_2,
                              std::size_t nth_index,
                              Comparator comparator = Comparator()
) {
  auto elem_idx = 0;
  ForwardIterator nth_element;



  return *nth_element;
}

#endif


/**
 * @brief   Finds the Nth element of the sorted lists in linear time
 * @tparam ForwardIterator
 * @tparam Comparator
 * @param start_1
 * @param end_1
 * @param start_2
 * @param end_2
 * @param nth_index
 * @param comparator
 * @return  the value of the nth_element
 */
template<typename ForwardIterator,
         typename Comparator = std::less<typename std::iterator_traits<ForwardIterator>::value_type>
>
auto nth_element_2list_linear(ForwardIterator start_1,
                              ForwardIterator end_1,
                              ForwardIterator start_2,
                              ForwardIterator end_2,
                              std::size_t nth_index,
                              Comparator comparator = Comparator()
) {
  auto elem_idx = 0;
  ForwardIterator nth_element;

  while((start_1 != end_1) && (start_2 != end_2)) {
    nth_element = comparator(*start_1, *start_2) ? start_1++ : start_2++;
    if(++elem_idx == nth_index)
      break;
  }


  while((elem_idx != nth_index) && (start_1 != end_1)) {
    nth_element = ++start_1;
  }

  while((elem_idx != nth_index) && (start_2 != end_2)) {
    nth_element = ++start_1;
  }

  return *nth_element;
}


} // algo::problems::nth_element::multilist

} // algo::problems::nth_element

} // algo::problems

} // algo

#endif //ALGO_KTH_LARGEST_MULTILIST_H
