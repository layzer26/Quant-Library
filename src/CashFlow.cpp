
#include "../include/quantlib/Cashflow.h"
namespace QuantLib {

    CashFlow::CashFlow(double amount, const Date& date)
        : m_amount(amount), m_date(date) {}

    // Getters
    double CashFlow::getAmount() const {
        return m_amount;
    }

    Date CashFlow::getDate() const {
        return m_date;
    }

}