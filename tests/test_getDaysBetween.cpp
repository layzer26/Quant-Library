#include "../include/quantlib/date.h"
using namespace QuantLib;

void test_getDaysBetween(){
    
    Date d1(1,1,2025);
    Date d2(1,2,2025);

    std::cout << "Days between " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear()
              << " and " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear()
              << " is: " << d1.getDaysBetween(d2) << std::endl;
}