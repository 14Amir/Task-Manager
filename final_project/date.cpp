#include <iostream>
#include "date.h"
#include <stdexcept>
#include <iomanip>

using namespace std;

Date::Date(unsigned int m, unsigned int d)
{
    setMonth(m);
    setDay(d);
}

//Date::Date(const Date &dateToCopy)
//{
//    setMonth(dateToCopy.getMonth());
//    setDay(dateToCopy.getDay());
//}
//
//Date::Date(string s)
//{
//    int m = stoi(s.substr(3));
//    int d = stoi(s.substr(0,2));
//    setMonth(m);
//    setDay(d);
//}

void Date::setMonth(unsigned int m)
{
    if(m >= 1 && m <= 12)
        month = m;
    else
        throw std::invalid_argument("Invalid month!");
}

unsigned int Date::getMonth() const
{
    return month;
}

void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        day = d;
    else
        throw std::invalid_argument("Invalid day for current month and year!");
}

unsigned int Date::getDay() const
{
    return day;
}

void Date::print() const
{
    std::cout << setfill('0') << setw(2) << day << "-" << month << std::endl;
}

bool Date::checkDay(unsigned int testDay) const
{
    unsigned int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(testDay <= daysPerMonth[month])
        return true;
    return false;
}

Date Date::operator-(int d1)
{
    Date temp1;
    int a = (this->getDay())- d1;
    temp1.setDay(a);
    return temp1;
}

Date Date::operator+(int d2)
{
    Date temp2;
    int b = (this->getDay())+ d2;
    temp2.setDay(b);
    return temp2;
}
