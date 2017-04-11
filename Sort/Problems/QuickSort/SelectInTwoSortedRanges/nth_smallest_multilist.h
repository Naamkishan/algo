#ifndef ALGO_NTH_SMALLEST_MULTILIST_H
#define ALGO_NTH_SMALLEST_MULTILIST_H

#include <functional>
#include <iterator>


namespace algo {

namespace problems {

namespace nth_element {

namespace multilist {


template<typename ForwardIterator,
    typename Comparator = std::less<typename std::iterator_traits<ForwardIterator>::value_type>
>
auto smallest_nth_element_2ranges_logarithmic(ForwardIterator start_1,
                                              ForwardIterator end_1,
                                              ForwardIterator start_2,
                                              ForwardIterator end_2,
                                              std::size_t nth_index,
                                              Comparator comparator = Comparator()
) {
  --nth_index; // ours start from 0 based while caller expects 1 based

  std::size_t mid_1;
  std::size_t mid_2;
  auto k = nth_index;

  while( (start_1 != end_1) && (start_2 != end_2) ) {
    mid_1 = std::distance(start_1, end_1) >> 1;
    mid_2 = std::distance(start_2, end_2) >> 1;

    if( (mid_1 + mid_2) < k ) {
      if( comparator(*std::next(start_1, mid_1), *std::next(start_2, mid_2)) ) {
        start_1 += (1 + mid_1);
        k -= (1 + mid_1);
      } else {
        start_2 += (1 + mid_2);
        k -= (1 + mid_2);
      }
    } else {
      if( comparator(*std::next(start_1, mid_1), *std::next(start_2, mid_2)) ) {
        end_2 = std::next(start_2, mid_2);
      } else {
        end_1 = std::next(start_1, mid_1);
      }
    }
  }


  auto select = (start_1 == end_1) ? start_2 : start_1;
  return *std::next(select, k);

}


} // algo::problems::nth_element::multilist
} // algo::problems::nth_element
} // algo::problems
} // algo

#endif //ALGO_NTH_SMALLEST_MULTILIST_H
