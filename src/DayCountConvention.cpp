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
                return static_cast<double>(days) / 365.0;
           
            case DayCount::Actual365:
                return static_cast<double>(days) / 365.0;
            case DayCount::Actual360:
                return static_cast<double>(days) / 360.0;
            // For Thirty/360, we need to handle the specific calculation
            // based on the convention, which assumes 30 days in each month.
            case DayCount::Thirty360: {
                int d1 = std::min(start.getDay(), 30);
                int d2 = std::min(end.getDay(), 30);
                int m1 = start.getMonth();
                int m2 = end.getMonth();
                int y1 = start.getYear();
                int y2 = end.getYear();

                int days360 = 360 * (y2 - y1) + 30 * (m2 - m1) + (d2 - d1);
                return static_cast<double>(days360) / 360.0;
            }
            default:
                throw std::invalid_argument("Unsupported day count convention.");
        }
       }
}
