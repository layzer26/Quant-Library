
#include <iostream>
#include "../include/quantlib/date.h"

using namespace QuantLib;
void test_isAfter() {
    Date d1(15, 6, 2023);
    Date d2(10, 6, 2023);
    Date d3(15, 6, 2023);
    Date d4(20, 5, 2022);

    std::cout << std::boolalpha;
    d1.display();
    std::cout << " after ";
    d2.display();
    std::cout << " " << d1.isAfter(d2) << "\n"; // true

    
    std::cout << "d2 after d1: " << d2.isAfter(d1) << "\n"; // false
    std::cout << "d1 after d3: " << d1.isAfter(d3) << "\n"; // false
    std::cout << "d1 after d4: " << d1.isAfter(d4) << "\n"; // true
}
