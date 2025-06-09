#include <quantlib/InterestRate.h>
#include <cmath>
#include <stdexcept>

namespace QuantLib {

InterestRate::InterestRate(double rate, CompoundingFrequency frequency, double variance)
    : m_annualRate(rate), m_frequency(frequency), m_variance(variance) {

    if (rate < 0) {
        throw std::invalid_argument("Interest rate cannot be negative");
    }
}

double InterestRate::simpleInterest(double principal, double years) const {
    return principal * (1 + m_annualRate * years);
}

double InterestRate::compoundInterest(double principal, double years) const {
    int n = 1;

    switch (m_frequency) {
        case CompoundingFrequency::Annual: n = 1; break;
        case CompoundingFrequency::SemiAnnual: n = 2; break;
        case CompoundingFrequency::Quarterly: n = 4; break;
        case CompoundingFrequency::Monthly: n = 12; break;
        case CompoundingFrequency::Daily: n = 365; break;
    }

    double effectiveRate = m_annualRate + m_variance;

    return principal * std::pow(1.0 + effectiveRate / n, n * years);
}

double InterestRate::compoundWithContributions(double principal, int years, double monthlyContribution) const {
    int n = 12; // monthly compounding for monthly contributions
    double effectiveRate = m_annualRate + m_variance;

    double futureValue = principal * std::pow(1.0 + effectiveRate / n, n * years);

    for (int i = 1; i <= years * 12; ++i) {
        futureValue += monthlyContribution * std::pow(1.0 + effectiveRate / n, n * years - i);
    }

    return futureValue;
}

// Getters
double InterestRate::getRate() const {
    return m_annualRate;
}

CompoundingFrequency InterestRate::getFrequency() const {
    return m_frequency;
}

double InterestRate::getVariance() const {
    return m_variance;
}

}
