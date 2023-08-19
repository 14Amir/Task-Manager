#include "task.h"
#include <iomanip>

task::task()
{

}

void task::settitle(string t)
{
    title = t;
}

string task::gettitle()
{
    return title;
}

void task::setstart(Time t1)
{
    start=t1;
}

Time task::getstart()
{
    return start;
}

void task::setend(Time t2)
{
    end=t2;
}

Time task::getend()
{
    return end;
}

void task::setlength()
{
    length = getend() - getstart();
}

Time task::getlength()
{
    return length;
}

void task::setdate(Date d)
{
    date=d;
}

Date task::getdate()
{
    return date;
}

istream &operator>>(istream &input, task &t)
{
  //cout << "title is ";
  char c;
  string s;
  input >> c;
  getline(input,s);
  if(c=='t')
  {
    t.settitle(s.substr(8));
  }
  if(c=='i')
  {
    t.settitle(s.substr(2));
  }
  cout << endl << "starts at ";
  int a;
  input >> setw(2) >> a;
  t.date.setDay(a);
  input.ignore();
  input >> setw(2) >> a;
  t.date.setMonth(a);
  cout << " ";
  input >> setw(2) >> a;
  t.start.setHour(a);
  input.ignore();
  input >> setw(2) >> a;
  t.start.setMinute(a);
  cout << endl << "ends at " << setfill('0') <<
           setw(2) << t.date.getDay() << "-" <<
           setw(2) << t.date.getMonth() << " " ;
  input >> setw(2) >> a;
  t.end.setHour(a);
  input.ignore();
  input >> setw(2) >> a;
  t.end.setMinute(a);
  cout << endl;
}

ostream &operator<<(ostream &output, task &t)
{
  output << '"' << t.gettitle() << '"' << " [" ;
 // t.start.hour << ":" << t.start.minute << " - " <<
  t.start.print();
  output << " - " ;
   t.end.print();
   output << ']' << endl;
  //t.end.hour << ":" << t.end.minute << ']' << endl;
}
