#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include "yearbook.h"
#include "employee.h"

using namespace std;

yearbook year;
vector<employee> employees;

void printtasks(int,int);
void today();
void month();
void addtask();
void printforfindtime(Date,Time,Time);
void findtime(Time);
void now1();
void free(Date,Time);
void addemployee();
void assigntask();
bool comparison(task , task );
//void sort_time_tasks(int,int);
void schedule();

int main()
{
    //open files
    fstream binFile("yearbook", ios::binary | ios::out | ios::in);

     if(!binFile)
    {
        cout << "Error in file!" << endl;
    }

    binFile.read(reinterpret_cast<char*>(&year), sizeof(yearbook));
    while(!binFile.eof())
    {
        binFile.read(reinterpret_cast<char*>(&year), sizeof(yearbook));
    }

//    time_t now = time(0);
//    tm *ltm = localtime(&now);

    string s ;//, ex = "exit" ;
    getline(cin,s);

    while(s != "exit")
    {

      if (s=="today")
          {
            year.getmonths(07).getdays(18).tasks[1].settitle("meeting") ;
            Time t,t1;
            t.setHour(15);
            t.setMinute(05);
            t1.setHour(15);
            t1.setMinute(55);
            year.getmonths(07).getdays(18).tasks[1].setstart(t);
            year.getmonths(07).getdays(18).tasks[1].setend(t1);
            today();
            //cin.ignore();
            cin >> s;
          }

      else if(s=="month")
          {
              month();
              cin >> s;
          }

      else if(s=="add task")
        {
          addtask();
          //cin.ignore();
          cin >> s;
          while(s!="done")
             addtask();
          cin >> s;
        }

      else if(s.substr(0,9)=="find time")
        {
          //Time t = s.substr(10);
          Time t;
          t.setHour(stoi(s.substr(10,12)));
          t.setMinute(stoi(s.substr(13,15)));
          findtime(t);
          cin >> s;
        }

      else if(s=="now")
          {
              now1();
              //cin.ignore();
              cin >> s;
          }
      else if(s.substr(0,4)=="free")
        {
          //Date freedate (s.substr(5,10)) ;
          //Time freetime (s.substr(11)) ;
          Date freedate;
          freedate.setDay(stoi(s.substr(5,7)));
          freedate.setMonth(stoi(s.substr(8,10)));

          Time freetime;
          freetime.setHour(stoi(s.substr(11,13)));
          freetime.setMinute(stoi(s.substr(14,16)));

          free(freedate,freetime);
          cin >> s;
        }

      else if(s=="add employee")
        {
          addemployee();
          cin >> s;
          while(s!="done")
             addemployee();
          cin >> s;
        }


      else if (s=="assign task")
        {
          assigntask();
          cin >> s;
          while(s!="done")
             assigntask();
          cin >> s;
        }

      else if (s=="schedule")
        {
          schedule();
          cin >> s;
          while(s!="done")
             schedule();
          cin >> s;
        }
    }

    //saving tasks in files in binary form and close files
    binFile.write(reinterpret_cast<char*>(&year), sizeof(yearbook));
    binFile.close();

    return 0;
}

void printtasks(int m,int d)
{
    int taskssize = year.getmonths(m).getdays(d).tasks.size();
    year.getmonths(m).getdays(d).tasks[1].getdate().print();
    for(int i=0;i<taskssize;++i)
        cout << '(' << i+1 << ") " << year.getmonths(m).getdays(d).tasks[i] << endl;
}

void today()
{
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int d=ltm->tm_mday;
  int m=1 + ltm->tm_mon;
  printtasks(m,d);
}

void month()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int m=1 + ltm->tm_mon;
    int length_of_month = year.getmonths(m).getsize();
    for(int i=0; i<length_of_month; ++i)
        printtasks(m,i+1);
}

void addtask()
{
    task temp;
    cin >> temp;
    int d= temp.getdate().getDay();
    int m= temp.getdate().getMonth();
    year.getmonths(m).getdays(d).tasks.push_back(temp);
    year.getmonths(m).getdays(d).sort();
}

void printforfindtime(Date date,Time t1 ,Time t2)
{
    date.print();
    cout << " [" ;
     t1.print();
     cout << " - " ;
     t2.print();
     cout << ']' << endl;
}

void findtime(Time T)
{
  time_t now2 = time(0);
  tm *ltm = localtime(&now2);
  Time now(ltm->tm_hour,ltm->tm_min);
  Time endday(23,59);
  Time firstofday(0,0);
  Time unit(0,1);
  int d = ltm->tm_mday;
  int m = 1 + ltm->tm_mon;
  Date today(m,d);
  Date tomorrow(m,d+1);
  int taskssize = year.getmonths(m).getdays(d).tasks.size();
  int j=0;
  bool flag = false;

  for(int i=0; i<taskssize; ++i)
    if(now <= year.getmonths(m).getdays(d).tasks[i].getstart())
       {
          j=i;
          break;
       }

  if(j==0)
    {
      Time temp = ((endday - year.getmonths(m).getdays(d).tasks.back().getend()) + unit + (year.getmonths(m).getdays(d+1).tasks[0].getstart())) ;
      if(T<=temp)
         {
             if(((endday - year.getmonths(m).getdays(d).tasks.back().getend()) + unit)>= T)
                printforfindtime(today, year.getmonths(m).getdays(d).tasks.back().getend(), (year.getmonths(m).getdays(d).tasks.back().getend())+T );
             else
             {
                printforfindtime(today, year.getmonths(m).getdays(d).tasks.back().getend(), endday );
                cout << " , " ;
                printforfindtime(tomorrow, firstofday, T - ((endday - year.getmonths(m).getdays(d).tasks.back().getend()) + unit));
             }
         }
    }

  if(T<=(year.getmonths(m).getdays(d).tasks[j].getstart()-now))
    printforfindtime(today, now, now + T);

  else
  {
      for(int k = d /*should change */; year.getmonths(m).getsize()+1; ++k)
        for(int i=1; i< (year.getmonths(m).getdays(k).tasks.size()-1) ; ++i)
           if(T<=((year.getmonths(m).getdays(k).tasks[i+1].getstart()) - (year.getmonths(m).getdays(k).tasks[i].getend())))
             {
               printforfindtime((today + k) - d , year.getmonths(m).getdays(k).tasks[i].getend(),year.getmonths(m).getdays(k).tasks[i].getend() + T);
               flag = true;
               return;
             }
  }

  static int x=1;
  while(!flag)
  {
      findtime(T-x);
      ++x;
  }

}

void now1()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << setfill('0') << setw(2) << ltm->tm_mday << "-" <<
                            setw(2) << 1 + ltm->tm_mon << " " <<
                            setw(2) << ltm->tm_hour << ":" <<
                            setw(2) << ltm->tm_min <<  endl;
}

void free(Date date,Time time)
{
    int m = date.getMonth();
    int d = date.getDay();
    int taskssize = year.getmonths(m).getdays(d).tasks.size();
    for(int i=0; i<taskssize; ++i)
       if((year.getmonths(m).getdays(d).tasks[i].getstart() <= time) && (year.getmonths(m).getdays(d).tasks[i].getend() >= time))
       {
         vector<task>::iterator it = year.getmonths(m).getdays(d).tasks.begin()+i;
         year.getmonths(m).getdays(d).tasks.erase(it);
       }
}

void addemployee()
{
    employee temp;
    cin >> temp;
    employees.push_back(temp);
}

void assigntask()
{
  char c;
  string s;
  employee temp;

  cin >> c;
  getline(cin,s);
  if(c=='s')
  {
    temp.setssid(s.substr(7));
  }
  if(c=='i')
  {
    temp.setssid(s.substr(2));
  }
  cout << endl << "task is ";
  getline(cin,s);

  int a,b,v;

  for(int i=0; i<13; ++i)
    for(int j=0; j<year.getmonths(i).getsize()+1; ++j)
      for(int k=0; k< year.getmonths(i).getdays(j).tasks.size(); ++k)
         if(year.getmonths(i).getdays(j).tasks[k].gettitle() == s)
           {
              a=i;
              b=j;
              v=k;
              return;
           }

  task t = year.getmonths(a).getdays(b).tasks[v];

  for(auto it = employees.begin(); it != employees.end(); ++it)
    if(temp.getssid() == it->getssid())
      {
        (*it).employeetasks.getmonths(a).getdays(b).tasks.push_back(t);
        (*it).employeetasks.getmonths(a).getdays(b).sort();
         break;
      }
}

  bool comparison(task a, task b)
{
     return (a.getlength() >= b.getlength());
}

//void sort_time_tasks(int m,int d)
//{
//    sort(year.getmonths(m).getdays(d).tasks.begin ,year.getmonths(m).getdays(d).tasks.end , comparison );
//}

void schedule()
{
  char c;
  string s;//,s1;
  employee temp;
  //Date date(s1);

  cin >> c;
  getline(cin,s);
  Date date;
  if(c=='d')
  {
    date.setDay(stoi(s.substr(7,9)));
    date.setMonth(stoi(s.substr(10,12))); //maybe i should define date out of here
  }
  if(c=='i')
  {
    date.setDay(stoi(s.substr(2,4)));
    date.setMonth(stoi(s.substr(5,7)));
  }

  cout << endl << "ssid is ";
  cin >> s;
  temp.setssid(s);

  int m = date.getMonth();
  int d = date.getDay();
  employee temp2;

  for(auto it = employees.begin(); it != employees.end(); ++it)
    if(temp.getssid() == it->getssid())
      {
        (*it).employeetasks.getmonths(m).getdays(d).tasks.clear();
        employee &temp2=(*it);
        break;
      }

  //sort_time_tasks(m,d);

  int i=0;
  for(auto it1 = temp2.employeetasks.getmonths(m).getdays(d).tasks.begin(); it1 != temp2.employeetasks.getmonths(m).getdays(d).tasks.end(); ++it1)
  {
    cout << '(' << i+1 << ") " << *it1 << endl;
     ++i; // form of using "i" should change
  }
}

