#include "../include/quantlib/InterestRate.h"
#include <iostream>

using namespace QuantLib;

void test_interest_rate ()

{
    InterestRate rate(0.05, CompoundingFrequency::Annual, 0); // 5% annual interest rate, compounded annually
    double principal = 1000.0;                                // Principal amount
    double years = 5;                                         // Time period in years
    try
    {
        double simpleInterest = rate.simpleInterest(principal, years);
        double compoundInterest = rate.compoundInterest(principal, years);
        double compoundWithContributions = rate.compoundWithContributions(principal, years, 100.0); // Monthly contribution of 100

        std::cout << "Simple Interest: " << simpleInterest << std::endl;
        std::cout << "Compound Interest: " << compoundInterest << std::endl;
        std::cout << "Compound Interest With Contributions: " << compoundWithContributions << std::endl;
    }

    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
   
}//run_interest_rate_test