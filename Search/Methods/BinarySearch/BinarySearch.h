#ifndef ALGO_BINARYSEARCH_H
#define ALGO_BINARYSEARCH_H

#include <vector>

template<typename T>
class BinarySearch {
 public:
  template<std::size_t N>
  BinarySearch(const T(&values)[N]) : container_(values, std::end(values)) {}

  bool find(const T& value) {
    std::size_t high = container_.size() - 1; // account for the 0 based index
    std::size_t low = 0;
    std::size_t mid;

    while(low <= high) {
      mid = (high + low)/2;
      if(value > container_[mid]) {
        low = mid;
      } else if(value < container_[mid]) {
        high = mid;
      } else {
        return true;
      }
    }
  }

 private:
  std::vector<T>  container_;
};

#endif //ALGO_BINARYSEARCH_H
