#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

Time::Time()
    : hour(0), minute(0)
{
}

Time::Time(unsigned int h, unsigned int m)
{
    setTime(h, m);
}

//Time::Time(string s)
//{
//    int h = stoi(s.substr(0,2));
//    int m = stoi(s.substr(3));
//    setTime(h, m);
//}

void Time::setTime(unsigned int h, unsigned int m)
{
    setHour(h);
    setMinute(m);
}

void Time::setHour(unsigned int h)
{
    if(h < 0 || h >= 24)
        hour = 0;
    else
        hour = h;
}

unsigned int Time::getHour()
{
    return hour;
}

void Time::setMinute(unsigned int m)
{
    if(m < 0 || m >= 60)
        minute = 0;
    else
        minute = m;
}

unsigned int Time::getMinute()
{
    return minute;
}

void Time::print()
{
    cout <<setfill('0')
         << setw(2) << getHour() << ':'
         << setw(2) << getMinute();
}

Time Time::operator-(Time t1)
{
    int h = (this-> getHour()) - t1.getHour();
    int m = (this-> getMinute()) - t1.getMinute();
    Time minus(h,m);
}

Time Time::operator-(int t)
{
    int h = this-> getHour();
    int m = (this-> getMinute()) - t;
    Time minus(h,m);
}

Time Time::operator+(Time t2)
{
    int h = (this-> getHour()) + t2.getHour();
    int m = (this-> getMinute()) + t2.getMinute();
    Time plus(h,m);
}

bool Time::operator<=(Time t3)
{
    if(this->getHour()< t3.getHour())
        return true;
    else if(this->getHour()== t3.getHour())
        if(this->getMinute()<= t3.getMinute())
          return true;
        else return false;
    else return false;
}

bool Time::operator>=(Time t4)
{
    if(this->getHour()> t4.getHour())
        return true;
    else if(this->getHour()== t4.getHour())
        if(this->getMinute()>= t4.getMinute())
          return true;
        else return false;
    else return false;
}
