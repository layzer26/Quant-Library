#include "quantlib/date.h"


using namespace QuantLib;

Date::Date (int d, int m, int y) : m_day(d), m_month(m), m_year(y) {}

//Getters
int Date::getDay() const {
    return m_day;
}
int Date::getMonth() const {
    return m_month;
}
int Date::getYear() const {
    return m_year;
}

//Display function
void Date::display() const {
    std::cout << "Date: " << m_day << "/" << m_month << "/" << m_year << std::endl;
}

bool Date::isBusinessDay() const {
    // Assuming a simple rule: weekdays are business days, weekends are not
    int dayOfWeekValue = Date::dayOfWeek(*this);
    return (dayOfWeekValue >= 2 && dayOfWeekValue <= 6); // 1=Sunday, ..., 5=Thursday, 6=Friday, 0=Saturday
}

//Compute Day Of week
int Date::dayOfWeek(const QuantLib::Date &d) {
    // Zeller's Congruence algorithm
    int y = d.getYear();
    int m = d.getMonth();
    int day = d.getDay();

    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100; // the year within the century
    int j = y / 100; // the zero-based century (actually floor(y/100))

    // Zeller's formula
    int f = day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
    return (f % 7 + 7) % 7; // Return value is in the range [0,6] where 0=Saturday, ..., 6=Friday
}

