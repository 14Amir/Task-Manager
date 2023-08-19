#ifndef YEARBOOK_H_INCLUDED
#define YEARBOOK_H_INCLUDED

#include "month.h"

class yearbook
{
public:
    yearbook()
      { months = new month[13];
        unsigned int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=0; i<13; ++i)
        this->months[i].setsize(daysPerMonth[i]);
      }
    ~ yearbook(){delete[] months;}
    month& getmonths(int i){ return months[i];}
private:
    month *months;
};

#endif // YEARBOOK_H_INCLUDED
