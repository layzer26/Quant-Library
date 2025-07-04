// Update the include path to match the actual location of date.h
#include "../include/quantlib/date.h"

using namespace QuantLib;

void test_date(){
    Date date(15, 3, 2023);
    date.display();

    if (date.isBusinessDay()){
        std::cout << "The date is a business day." << std::endl;
    } else {
        std::cout << "The date is not a business day." << std::endl;
    }

    
 }//run_date_test
