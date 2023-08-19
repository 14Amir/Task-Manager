#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<string>
#include <iostream>

class Date
{
public:
    explicit Date(unsigned int = 1, unsigned int = 1);
    //Date(const Date&);
    //Date(string);
    void setMonth(unsigned int);
    unsigned int getMonth() const;
    void setDay(unsigned int);
    unsigned int getDay() const;

    void print() const;
    Date operator-(int);
    Date operator+(int);

private:
    unsigned int month;
    unsigned int day;

    bool checkDay(unsigned int) const;
};


#endif // DATE_H_INCLUDED
