#include "../include/quantlib/CashflowSchedule.h"
#include "../include/quantlib/Cashflow.h"
#include <iostream>
#include <algorithm>

namespace QuantLib
{

    void CashflowSchedule::addCashFlow(CashFlow &cashflow)
    {
        if (!containsDuplicate(cashflow))
        {
            m_cashflow.push_back(cashflow);
        }
        else
        {
            std::cout << "Cash flow on "
                      << cashflow.getDate().getDay() << "/"
                      << cashflow.getDate().getMonth() << "/"
                      << cashflow.getDate().getYear()
                      << " already exists. Skipping.\n";
        }
    }

    void CashflowSchedule::generateMonthlyContributions(Date &start, Date &end, double amount)
    {
        Date current = start;
        while (!current.isAfter(end))
        {
            CashFlow cf(amount,current);
            addCashFlow(cf);
            current = Date(current.getDay(), current.getMonth() + 1, current.getYear());
        }
    }

    double CashflowSchedule::getTotalCashFlow() const
    {
        double total = 0.0;
        for (const auto &cf : m_cashflow)
        {
            total += cf.getAmount();
        }
        return total;
    }

    const std::vector<CashFlow> &CashflowSchedule::getCashFlows() const
    {
        return m_cashflow;
    }

    bool CashflowSchedule::containsDuplicate(const CashFlow &cashflow) const
    {
        return std::any_of(m_cashflow.begin(), m_cashflow.end(),
                           [&cashflow](const CashFlow &cf)
                           {
                               return cf.getDate().getDay() == cashflow.getDate().getDay() &&
                                      cf.getDate().getMonth() == cashflow.getDate().getMonth() &&
                                      cf.getDate().getYear() == cashflow.getDate().getYear();
                           });
    }

}
