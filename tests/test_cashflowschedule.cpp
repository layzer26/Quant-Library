
#include "../include/quantlib/CashflowSchedule.h"
#include "../include/quantlib/Cashflow.h"
#include "../include/quantlib/Date.h"

#include <iostream>
using namespace QuantLib;

void test_cashflowschedule (){
    // Define start and end dates for monthly contributions
    Date start(1, 1, 2023);
    Date end(1, 12, 2023);

    
    CashflowSchedule schedule;
    // Generate monthly contributions of $1000
    schedule.generateMonthlyContributions(start, end, 1000.0);

    // Get total cash flow
    double totalCashFlow = schedule.getTotalCashFlow();
    std::cout << "Total Cash Flow: $" << totalCashFlow << std::endl;

    // Display all cash flows
    const auto& cashFlows = schedule.getCashFlows();
    for (const auto& cf : cashFlows) {
        std::cout << "Cash Flow on " << cf.getDate().getDay() << "/" 
                  << cf.getDate().getMonth() << "/" 
                  << cf.getDate().getYear() 
                  << ": $" << cf.getAmount() << std::endl;
    }
}