#ifndef dayH
#define dayH

#include <iostream>
#include "appointment.h"
using namespace std;

class Day
{
  short day;
  short month;
  Appointment *appts[8];
  short apptCount;
public:
  short getMonth() const;
  short getDay() const;
  Day();
	Day(const short, const short);
  ~Day();
  int compareDate(short mo, short d) const;
  void printAppts() const;
  void printSubject(const char *s, bool &found) const;
  void read();
  void reset(short mo, short d);
  Day& operator= (const Day &d);
	Day& operator+= (const Day &d);
  friend ostream& operator<<(ostream&, const Day&);
  friend istream& operator>>(istream &is, Day &d);
}; 
#endif
