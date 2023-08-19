#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED

#include <vector>
#include <algorithm>

#include "task.h"
//const int n=30;

class day
{
public:
    vector<task> tasks;

    bool taskComparataor(task t1, task t2)
    {
       if(t1.getstart().getHour() < t2.getstart().getHour())
        return true;
       else if(t1.getstart().getHour() == t2.getstart().getHour())
         if(t1.getstart().getMinute()< t2.getstart().getMinute())
           return true;
         else return false;
       else return false;
    }

    void sort()
    {
        //sort(tasks.begin(),tasks.end(),taskComparataor);
        //sort(tasks.front(),tasks.back(),taskComparataor);
        //sort(tasks,tasks+tasks.size(),taskComparataor);
        for(int i=0; i< tasks.size(); ++i)
            for(int j=i+1; j< tasks.size(); ++j)
              if(!taskComparataor(tasks[i],tasks[j]))
                {
                   task temp4;
                   temp4 = tasks[i];
                   tasks[i]=tasks[j];
                   tasks[j]=temp4;
                }
    }
};
#endif // DAY_H_INCLUDED
