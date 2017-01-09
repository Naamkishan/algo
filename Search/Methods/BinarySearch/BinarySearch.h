#ifndef ALGO_BINARYSEARCH_H
#define ALGO_BINARYSEARCH_H

#include <vector>

template<typename T>
class BinarySearch {
 public:
  template<std::size_t N>
  BinarySearch(const T(&values)[N]) : container_(values, std::end(values)) {}

  int find(const T& value) {
    int high = container_.size() - 1; // account for the 0 based index
    int low = 0;
    int mid;

    while(low <= high) {
      mid = low + (high - low)/2;
      if(value > container_[mid]) {
        low = mid + 1;
      } else if(value < container_[mid]) {
        high = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }

 private:
  std::vector<T>  container_;
};

#endif //ALGO_BINARYSEARCH_H
