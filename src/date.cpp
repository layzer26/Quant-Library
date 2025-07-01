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
/*int Date::getToday() const {
    
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return now->tm_mday;
}
*/
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
    int year = d.getYear();
    int month = d.getMonth();
    int day = d.getDay();

    if (month < 3) {
        month += 12;
        year--;
    }

    int yearCentury= year % 100; // the year within the century
    int zeroBasedCentury = year / 100; // the zero-based century (actually floor(y/100))

    // Zeller's formula
    int f = day + (13 * (month + 1)) / 5 + yearCentury + yearCentury / 4 + zeroBasedCentury / 4 - 2 * zeroBasedCentury;
    return (f % 7 + 7) % 7; // Return value is in the range [0,6] where 0=Saturday, ..., 6=Friday
}

int Date::getDaysBetween(const Date &other) const {
    // Simple implementation assuming all months have 30 days and ignoring leap years
    int daysInYear = 365;
    int daysInMonth = 30;

    int totalDaysThis = m_year * daysInYear + m_month * daysInMonth + m_day;
    int totalDaysOther = other.getYear() * daysInYear + other.getMonth() * daysInMonth + other.getDay();

    return totalDaysOther - totalDaysThis;
}

bool Date::isAfter(const Date& other) const {
    // Check if this date is after the start date and before the end date
   if (m_year>other.getYear()) {
        return true;
    } 
    if (m_year <other.getYear()) {
        return false;
    }

    if (m_month >other.getMonth()){
        return true;
    }
    if (m_month < other.getMonth()) {
        return false;
    }
    return m_day > other.getDay(); // Compare days if year and month are the same
}

