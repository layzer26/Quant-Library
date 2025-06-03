#pragma once
#include <iostream>

namespace QuantLib {
class Date {

    
    public:
        // Constructors
        Date(int d, int m, int y) ;

        // Getters
        int getDay() const ;
        int getMonth() const ;
        int getYear() const ;

        bool isBusinessDay()const;

        int static dayOfWeek( const QuantLib::Date &d);

        // Display function
        void display() const;
            

    private:
        int m_day;
        int m_month;
        int m_year;

        //int dayOfWeek(DAte &d) const;
    }; //QuantLib::Date

    

} //namespace QuantLib
