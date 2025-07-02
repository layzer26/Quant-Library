#include "../include/quantlib/Cashflow.h"
#include <vector>
namespace QuantLib
{
    class CashflowSchedule
    {
    public:
       // CashflowSchedule(CashFlow& cf) ;
        void addCashFlow(CashFlow &cashflow);
        void generateMonthlyContributions(Date &start, Date &end, double amount);

        double getTotalCashFlow() const;
        const std::vector<CashFlow> &getCashFlows() const;

    private:
        std::vector<CashFlow> m_cashflow; // Vector to store cash flows
        bool containsDuplicate(const CashFlow &cashflow) const;
    };
} // namespace QuantLib