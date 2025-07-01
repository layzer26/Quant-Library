
#ifndef QUANTLIB_CASHFLOW_H
#define QUANTLIB_CASHFLOW_H

#include "date.h"
namespace QuantLib{

class CashFlow {
public:
    CashFlow(double amount, const Date& date);
    // Getters
    double getAmount() const;
    Date getDate() const;

private:
    double m_amount; // Cash flow amount
    Date m_date;     // Date of the cash flow
};
} // namespace QuantLib


#endif