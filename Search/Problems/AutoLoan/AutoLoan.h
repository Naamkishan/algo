#ifndef ALGO_AUTOLOAN_H
#define ALGO_AUTOLOAN_H

#include <cmath>
#include <exception>

namespace AutoLoan {

bool is_essentially_equal(const double& a, const double& b, const double& tolerance = 1e-9) {
  return (std::fabs(a - b) <= tolerance);
}

double remaining_principal(double principal, double monthly_payment, int term, double interest) {
  double monthly_interest = interest/1200;  // convert the annualised interest into monthly.
  if((principal * monthly_interest) > monthly_payment)
    return 1;

  for(int i{0}; i < term; ++i)
    principal = principal * (1 + monthly_interest) - monthly_payment;

  return principal;
}

/**
 * @brief   Autloan's get interest function
 *
 * @param price                 : principal
 * @param monthly_payment       : emi
 * @param loan_term             : loan tenure in terms of number of months
 * @param tolerance             : the allowed differce between two doubles that can be essentially be considered equal
 * @return      annualised interest rate
 */
double interest_rate(double price,
                     double monthly_payment,
                     int loan_term,
                     double tolerance = 1e-9) {
  double price_left_to_pay{1.00}; // initial value to ensure that the loops does not get terminated by default
  double low_int = {0.0};
  double monthly_int = {0.00};
  double high_int = {100.00};

  while(!is_essentially_equal(price_left_to_pay, 0.00, tolerance)) {
    monthly_int = low_int + (high_int - low_int)/2;
    price_left_to_pay = remaining_principal(price, monthly_payment, loan_term, monthly_int);
    // we have undershot the interest rate
    if(price_left_to_pay < 0) {
      low_int = monthly_int;
    } else {
      high_int = monthly_int;
    }
  }

  return monthly_int;
}


} // namespace AutoLoan

#endif //ALGO_AUTOLOAN_H
