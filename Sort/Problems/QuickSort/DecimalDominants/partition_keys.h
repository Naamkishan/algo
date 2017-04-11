#ifndef ALGO_PARTITION_KEYS_H
#define ALGO_PARTITION_KEYS_H

#include <iterator>
#include <functional>
#include <utility>

namespace algo {

namespace problems {

namespace partition {

/**
 * @brief   partition the given range by the condition provided (unary predicate paramater)
 * @tparam ForwardIterator
 * @tparam UnaryPredicate : functor deciding partition boundary
 * @param begin : start of range
 * @param end  : end of range
 * @param pred  - unary predicate
 * @return  iterator to the first element that does not satisfy the predicate
 */
template<typename ForwardIterator,
    typename UnaryPredicate
>
auto partition_range_by_predicate(ForwardIterator begin, ForwardIterator end, UnaryPredicate pred) {
  if(begin != end) {
    --end;

    for(; (begin != end) && pred(*begin); ++begin);

    if(begin != end)
      std::iter_swap(begin, end);

    for(; (begin != end) && !pred(*end); --end);
  }

  return begin;
}


} // algo::problems::partition

} // algo::problems

} // algo

#endif //ALGO_PARTITION_KEYS_H
