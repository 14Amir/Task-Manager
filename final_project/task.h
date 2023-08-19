#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

#include<iostream>
#include<string>

#include "time.h"
#include "date.h"

using namespace std;

class task
{
    friend istream &operator>>(istream&, task&);
    friend ostream &operator<<(ostream&, task&);
public:
    task();
    void settitle(string);
    string gettitle();
    void setstart(Time);
    Time getstart();
    void setend(Time);
    Time getend();
    void setlength();
    Time getlength();
    void setdate(Date);
    Date getdate();

private:
    string title;
    Time start,end,length;
    Date date;
};

#endif // TASK_H_INCLUDED
