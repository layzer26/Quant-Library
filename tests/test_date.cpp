#include "quantlib/date.h"

using namespace QuantLib;
int main (){
    Date date(15, 3, 2023);
    date.display();

    if (date.isBusinessDay()){
        std::cout << "The date is a business day." << std::endl;
    } else {
        std::cout << "The date is not a business day." << std::endl;
    }

    return 0;
 }//main
