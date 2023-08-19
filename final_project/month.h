#ifndef MONTH_H_INCLUDED
#define MONTH_H_INCLUDED

#include "day.h"

class month
{
    friend class yearbook;
public:
    month(){ days = new day[size+1];}
    ~ month(){delete[] days;}
    day& getdays(int i){ return days[i];}
    void setsize(unsigned int s){ size=s;}
    unsigned int getsize() const {return size;}

private:
    day *days;
    unsigned int size;
};


#endif // MONTH_H_INCLUDED
