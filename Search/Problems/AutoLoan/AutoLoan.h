#ifndef ALGO_AUTOLOAN_H
#define ALGO_AUTOLOAN_H

#include <exception>

namespace AutoLoan {

/**
 * @brief   Autloan's get interest function
 *
 * @param price
 * @param monthly_payment
 * @param loan_term
 * @return
 */
double interest_rate(double price, double monthly_payment, int loan_term) {
  throw std::logic_error("Function not implemented");


}

} // namespace AutoLoan

#endif //ALGO_AUTOLOAN_H
