#pragma once
#include <cmath>

namespace QuantLib {

    enum class CompoundingFrequency {
        Annual,
        SemiAnnual,
        Quarterly,
        Monthly,
        Daily
    };

    class InterestRate {
    private:
        double m_annualRate;
        CompoundingFrequency m_frequency;
        double m_variance;

    public:
        InterestRate(double rate, CompoundingFrequency frequency, double variance = 0.0);

        double simpleInterest(double principal, double years) const;

        double compoundInterest(double principal, double years) const;

        double compoundWithContributions(double principal, int years, double monthlyContribution) const;

        double getRate() const;
        CompoundingFrequency getFrequency() const;
        double getVariance() const;
    };

}
