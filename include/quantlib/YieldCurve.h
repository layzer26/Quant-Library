
#ifndef QUANTLIB_YIELDCURVE_H
#define QUANTLIB_YIELDCURVE_H

#include "date.h"
#include "DayCountConvention.h"
#include <vector>
#include <utility>

namespace QuantLib
{
    class YieldCurve
    {
    public:
        YieldCurve(const Date &today, DayCount convention = DayCount::Actual365);
        // Add a zero rate with its associated maturity date
        void addZeroRate(const Date &maturity, double zeroRate);

        // Get zero rate for a given date
        double getZeroRate(const Date &date) const;

        // Get a discount factor for a given date
        double getDiscountFactor(const Date &date) const;

    private:
        Date m_today; // Today's date
        DayCount m_convention; 
        std::vector<std::pair<Date, double>> m_zeroRates; // Vector of pairs (maturity date, zero rate)
    };
};
#endif // QUANTLIB_YIELDCURVE_H