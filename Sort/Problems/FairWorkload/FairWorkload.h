#ifndef ALGO_FAIRWORKLOAD_H
#define ALGO_FAIRWORKLOAD_H

#include <algorithm>
#include <iterator>


/**
 *
 * @param begin         : start of range
 * @param end           : end of range
 * @param workers       : number of workers in amongst which work is to be divided
 * @return
 */
template<typename ForwardIterator>
auto get_most_work(ForwardIterator begin, ForwardIterator end,    // range of container
                   unsigned int workers) {
  using Type = typename std::iterator_traits<ForwardIterator>::value_type;

  Type cur_max_load = *std::max_element(begin, end);
  Type high_max_load = std::accumulate(begin, end, 0);

  while(cur_max_load < high_max_load) {
    Type proposed_max_load = cur_max_load + ((high_max_load - cur_max_load)>>1); // using right shift to divide by 2

    Type required_workers{1}, current_load{0};

    for(ForwardIterator itr{begin}; itr != end; std::advance(itr, 1)) {
      if((current_load + *itr) <= proposed_max_load) {
        current_load += *itr;
      } else {
        // assign it to the next worker
        ++required_workers;
        current_load = *itr;
      }
    }

    if(required_workers <= workers) {
      high_max_load = proposed_max_load;
    } else {
      cur_max_load = (proposed_max_load + 1);
    }
  }

  return cur_max_load;
}


#endif //ALGO_FAIRWORKLOAD_H
