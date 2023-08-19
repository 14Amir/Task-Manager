#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <string>
#include <iostream>

class Time
{
public:
    Time();
    Time(unsigned int, unsigned int);
    //Time(string);
    void setTime(unsigned int, unsigned int);
    void setHour(unsigned int);
    unsigned int getHour();
    void setMinute(unsigned int);
    unsigned int getMinute();
    void print();

    Time operator-(Time);
    Time operator-(int);
    Time operator+(Time);
    bool operator<=(Time);
    bool operator>=(Time);
private:
    unsigned int hour;
    unsigned int minute;
};


#endif // TIME_H_INCLUDED
