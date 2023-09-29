#include <iostream>

#ifndef DATE_H
#define DATE_H

class Date {
    int year;
    int month;
    int day;

public:
    // Constructors
    Date();
    Date(int year, int month, int day);
    Date(int d); 

    // Arithmetic Operators
    Date operator+(int days);
    Date operator-();
    Date operator-(int days);
    Date operator++();
    Date operator++(int);
    Date operator--();
    Date operator--(int);
    int operator-(Date d);
    int totalDaysFromDate(int y, int m, int d);
    Date operator+=(int days);
    Date operator-=(int days);
    
    // Boolean Operators
    bool operator==(Date d);
    bool operator==(int s);
    bool operator!=(Date d);
    bool operator<(Date d);
    bool operator>(Date d);
    bool operator>=(Date d);
    bool operator<=(Date d);

    // Validate Date Function
    bool isValidDate() ;

    // Friend Functions
    friend bool operator==(int i, Date d);
    friend std::ostream& operator<<(std::ostream& o, Date d);
    friend std::istream& operator>>(std::istream& i, Date& d);
};

bool isLeapYear(int year);
int daysInMonth(int month, int year);

#endif // DATE_H
