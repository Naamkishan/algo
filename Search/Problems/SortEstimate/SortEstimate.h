#ifndef ALGO_AUTOLOAN_H
#define ALGO_AUTOLOAN_H

#include <cmath>
#include <exception>

#include <utility.h>

namespace SortEstimate {

/**
 *
 * @param constant   - algo's constant
 * @param numbers    - number of integers to process
 * @return  double - time taken to process n integers
 */
double get_processing_time(const int constant, const double& numbers) {
  return ( static_cast<double>(constant) * numbers * std::log(numbers)/std::log(2) );
}

/**
 * @brief       determines how many integers can be processed for for a given algorithm having O(n): c*n*lg(n)
 * @param c     constant of the underlying algo's O(n)
 *                  Range: 1 - 100
 * @param time  time taken to process "n" integers by the algorithm
 *                  Range: 1 - 2000000000
 * @return      double -> number of integers that can be processed
 */
double how_many(int c, int time, double tolerance = 1e-9) {

  double numbers{1.00};   // current number of integers being processed
  double high_num{2000000000};  // max number of integers that can be processed
  double incr;
  double processing_time;

  do {
    incr = (high_num - numbers)/2;
    processing_time = get_processing_time(c, numbers + incr);
    if(processing_time < time) {
      numbers += incr;  // can process more integers - we still have some leeway
    } else {
      high_num = (numbers + incr);
    }
  } while(!Utility::is_essentially_equal(numbers, numbers + incr, tolerance));

  return numbers;


}

} // namespace SortEstimate

#endif //ALGO_AUTOLOAN_H
