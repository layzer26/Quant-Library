#include "../include/quantlib/YieldCurve.h"
using namespace QuantLib;
void test_YieldCurve() {
    Date today(1, 1, 2023);
    YieldCurve curve(today, DayCount::Actual365);

    // Add some zero rates
    curve.addZeroRate(Date(1, 1, 2024), 0.05); // 5% for 1 year
    curve.addZeroRate(Date(1, 1, 2025), 0.06); // 6% for 2 years
    curve.addZeroRate(Date(1, 1, 2026), 0.07); // 7% for 3 years

    // Get zero rates
    Date futureDate(1, 1, 2024);
    double rate = curve.getZeroRate(futureDate);
    std::cout << "Zero rate for " << futureDate.getDay() << "/" << futureDate.getMonth() << "/" << futureDate.getYear() << ": " << rate << std::endl;

    // Get discount factor
    double discountFactor = curve.getDiscountFactor(futureDate);
    std::cout << "Discount factor for " << futureDate.getDay() << "/" << futureDate.getMonth() << "/" << futureDate.getYear() << ": " << discountFactor << std::endl;
}