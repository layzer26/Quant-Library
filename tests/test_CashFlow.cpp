#include "../include/quantlib/Cashflow.h"
#include "../include/quantlib/Date.h"

using namespace QuantLib;

void test_CashFlow() {
    // Create a cash flow on a specific date
    Date cashflowDate(15, 9, 2025);
    CashFlow cashflow(1000.0, cashflowDate);

    // Test getters
    double amount = cashflow.getAmount();
    Date date = cashflow.getDate();
    Date today (1,7,2025); // Assuming getToday() returns the current date
    cashflow.getDate().isAfter(today); // Check if the cashflow date is after today

    // Output the results
    std::cout << "Cashflow Amount: " << amount << std::endl;
    std::cout << "Cashflow Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << std::endl;
}