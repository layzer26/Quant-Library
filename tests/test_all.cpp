#include <iostream>
#include "../include/quantlib/date.h"

using namespace QuantLib;

extern void test_date();
extern void test_interest_rate();
extern void test_getDaysBetween();
extern void test_isAfter();
extern void test_YieldCurve();

int main (){
     

    std::cout << "Running all tests..." << std::endl;
    
    std::cout << "Testing Date..." << std::endl;
    test_date();

    std::cout << "Testing Interest Rate..." << std::endl;
    test_interest_rate();

    std::cout << "daysBetween test..." << std::endl;
    test_getDaysBetween();

    std::cout << "Testing isAfter..." << std::endl;
    test_isAfter();

    std::cout <<"Yield Curve test..." << std::endl;
    test_YieldCurve();

    return 0;   
}