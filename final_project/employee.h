#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include<iostream>
#include<string>

#include "time.h"
#include "yearbook.h"
#include <vector>
#include <algorithm>

class employee
{
    friend istream &operator>>(istream&, employee&);
    //friend ostream &operator<<(ostream&, employee&);
public:
    employee();
    void setname(string);
    string getname();
    void setssid(string);
    string getssid();
    void setstart(Time);
    Time getstart();
    void setend(Time);
    Time getend();

    yearbook employeetasks;
private:
    string name,ssid;
    Time start,end;
};

#endif // EMPLOYEE_H_INCLUDED
