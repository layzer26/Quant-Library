#include "../include/quantlib/YieldCurve.h"
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <cmath>

namespace QuantLib {
    YieldCurve::YieldCurve(const Date& today, DayCount convention)
        : m_today(today), m_convention(convention) {
        
    }

    void YieldCurve::addZeroRate(const Date& maturity, double zeroRate) {
        if (maturity.isAfter(m_today)) {
        m_zeroRates.emplace_back(maturity, zeroRate);        
        }
        else {
            throw std::invalid_argument("Maturity date must be after today's date.");
        }
        std::sort(m_zeroRates.begin(), m_zeroRates.end(),
            [](const std::pair<Date, double>& a, const std::pair<Date, double>& b) {
                return a.first.isAfter(b.first);
            });
    
    }
    double YieldCurve::getZeroRate(const Date& date) const {
    if (date.isAfter(m_today) == false)
        return 0.0;

    for (size_t i = 0; i < m_zeroRates.size(); ++i) {
        if (date.getDaysBetween(m_zeroRates[i].first) == 0)
            return m_zeroRates[i].second;

        if (date.isAfter(m_zeroRates[i].first) == false && i > 0) {
            const auto& [d1, r1] = m_zeroRates[i - 1];
            const auto& [d2, r2] = m_zeroRates[i];

            double t1 = DayCountConvention::yearFraction(m_today, d1, m_convention);
            double t2 = DayCountConvention::yearFraction(m_today, d2, m_convention);
            double t  = DayCountConvention::yearFraction(m_today, date, m_convention);

            return r1 + (r2 - r1) * ((t - t1) / (t2 - t1));  // linear interpolation
        }
    }

    return m_zeroRates.back().second;  // extrapolate with last rate
}

double YieldCurve::getDiscountFactor(const Date& date) const {
    double t = DayCountConvention::yearFraction(m_today, date, m_convention);
    double r = getZeroRate(date);
    return std::exp(-r * t);
}

} // namespace QuantLib

