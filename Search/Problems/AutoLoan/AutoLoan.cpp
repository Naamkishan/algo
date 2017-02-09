#include <gtest/gtest.h>
#include "AutoLoan.h"

namespace {
const double TOLERANCE = 1e-9;
}


/**
 * @details     Autoloan: Calculate interest rate
 *
 * Constraints:
 *  prince : [1, 1000000]
 *  monthly payment : [0, price/2]
 *  loan term : [1, 600]
 *
 *  Result Rate : [0, 100]
 */

TEST(TestAutoLoan, Tenure68Price6800Emi100) {
  double price = 6800.0;
  double monthly_payment = 100.0;
  int loan_term = 68;

  double expected_rate = 0.0;

  double actual_rate = AutoLoan::interest_rate(price, monthly_payment, loan_term, TOLERANCE);

  EXPECT_NEAR(expected_rate, actual_rate, TOLERANCE);
}

TEST(TestAutoLoan, Tenure4Price2000Emi510) {
  double price = 2000.0;
  double monthly_payment = 510.0;
  int loan_term = 4;

  double expected_rate = 9.56205462458368;

  double actual_rate = AutoLoan::interest_rate(price, monthly_payment, loan_term, TOLERANCE);

  EXPECT_NEAR(expected_rate, actual_rate, TOLERANCE);
}


TEST(TestAutoLoan, Tenure48Price15000Emi365) {
  double price = 15000.0;
  double monthly_payment = 364.0;
  int loan_term = 48;

  double expected_rate = 7.687856394581649;

  double actual_rate = AutoLoan::interest_rate(price, monthly_payment, loan_term, TOLERANCE);

  EXPECT_NEAR(expected_rate, actual_rate, TOLERANCE);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
