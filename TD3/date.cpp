#include "date.h"
#include <stdexcept>
using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;
}

// Constructors

Date::Date() : year(2002), month(1), day(17) {}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    if (!isValidDate()) {
        throw invalid_argument("Invalid date");
    }
}

Date::Date(int d) {
    struct tm* timeinfo;
    time_t rawtime = static_cast<time_t>(d);

    timeinfo = localtime(&rawtime);

    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
}

// Validate Date Function

bool Date::isValidDate() {
    return day >= 1 && day <= daysInMonth(month, year) && month >= 1 && month <= 12;
}

// Arithmetic operators

Date Date::operator+(int d) {
    Date newDate = *this;  
    for (int i=0;i<d;i++){
        ++newDate;
    }
    return newDate;
}

Date Date::operator-(int days) {
    Date newDate = *this;
    for (int i=0; i<days; i++){
        --newDate;
    }
    return newDate;
}

Date Date::operator++() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date Date::operator--() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

int Date::operator-(Date d) {
    int thisTotalDays = totalDaysFromDate(year, month, day);
    int totalDays = totalDaysFromDate(d.year, d.month, d.day);
    return thisTotalDays - totalDays;
}

int Date::totalDaysFromDate(int y, int m, int d) {
    int totalDays = d;
    
    for (int i = 1; i < m; ++i) {
        totalDays += daysInMonth(i, y);
    }
    
    for (int i = 1; i < y; ++i) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    
    return totalDays;
}

Date Date::operator+=(int days) {
    for (int i = 0; i < days; i++) {
        ++(*this);
    }
    return *this;
}

Date Date::operator-=(int days) {
    for (int i = 0; i < days; i++) {
        --(*this);
    }
    return *this;
}

// Boolean operators

bool Date::operator==(Date d) {
    return (year==d.year && month==d.month && day==d.day);
}

bool Date::operator==(int i) {
    Date d2(i);
    return *this==d2;
}

bool Date::operator!=(Date d) {
    return (year!=d.year || month!=d.month || day!=d.day);
}

bool Date::operator<(Date d) {
    if (year < d.year) {
        return true;
    } else if (year > d.year) {
        return false;
    }
    if (month < d.month) {
        return true;
    } else if (month > d.month) {
        return false;
    }
    return day < d.day;
}

bool Date::operator>(Date d) {
    return d < *this;
}

bool Date::operator>=(Date d) {
    return !(*this < d);
}

bool Date::operator<=(Date d) {
    return (*this < d) || (*this == d);
}

// Friend functions

bool operator==(int i, Date d) {
    return d==i;
}

ostream& operator<<(ostream& o, Date d) {
    string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    o << months[d.month - 1] << " " << d.day << ", " << d.year << endl;
    return o;
}

istream& operator>>(istream& i, Date& d) {
    char slash;
    i >> d.year >> slash >> d.month >> slash >> d.day;
    return i;
}


