#include "employee.h"
#include <iomanip>

employee::employee()
{

}

void employee::setname(string t)
{
    name = t;
}

string employee::getname()
{
    return name;
}

void employee::setssid(string t)
{
    name = t;
}

string employee::getssid()
{
    return name;
}

void employee::setstart(Time t1)
{
    start=t1;
}

Time employee::getstart()
{
    return start;
}

void employee::setend(Time t2)
{
    end=t2;
}

Time employee::getend()
{
    return end;
}

istream &operator>>(istream &input, employee &e)
{
  char c;
  string s;
  input >> c;
  getline(input,s);
  if(c=='n')
  {
    e.setname(s.substr(7));
  }
  if(c=='i')
  {
    e.setname(s.substr(2));
  }
  cout << endl << "ssid is ";
  input >> s;
  e.setssid(s);
  cout << endl << "starts at ";
  int a;
  input >> setw(2) >> a;
  e.start.setHour(a);
  input.ignore();
  input >> setw(2) >> a;
  e.start.setMinute(a);
  cout << endl << "ends at ";
  input >> setw(2) >> a;
  e.end.setHour(a);
  input.ignore();
  input >> setw(2) >> a;
  e.end.setMinute(a);
  cout << endl;
}

//ostream &operator<<(ostream &output, employee &e)
//{
//
//}
