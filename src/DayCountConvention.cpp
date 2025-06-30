#include "../include/quantlib/DayCountConvention.h"
#include <stdexcept>
#include <algorithm>

namespace QuantLib {
    double DayCountConvention::yearFraction(const Date &start, const Date &end, DayCount convention) {
        if (start.isAfter(end) ) {
            throw std::invalid_argument("Start date must be before end date.");
        }
        int days = start.getDaysBetween(end);

        switch (convention) {
            case DayCount::ActualActual:
                return days /365.0;
            case DayCount::Actual360:
                return days /360.0;
            case DayCount::Actual365:
                return days /365.0;
            case DayCount::Thirty360:
                int d1 = start.getDay();
                int d2 = end.getDay();
                int m1 = start.getMonth();
                int m2 = end.getMonth();
                int y1 = start.getYear();
                int y2 = end.getYear();
            default:
                throw std::invalid_argument("Unsupported day count convention.");
        }
    }
}
