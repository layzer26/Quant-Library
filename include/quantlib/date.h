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

        void setMonth(int month );
        //int getToday()const;
        
        bool isBusinessDay()const;

        int static dayOfWeek( const QuantLib::Date &d);

        // Display function
        void display() const;

        int getDaysBetween(const Date &other) const;
        bool isAfter(const Date& other ) const;
            
                

    private:
        int m_day;
        int m_month;
        int m_year;

        //int dayOfWeek(DAte &d) const;
    }; //QuantLib::Date

    

} //namespace QuantLib
