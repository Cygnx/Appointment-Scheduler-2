
#ifndef timeH
#define timeH

#include <iostream>

using namespace std;

class Time
{
  short hour;
  short minute;
public:
  friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream &is, Time &t);
  void read();
	void setHour(const char* str);
	void setMinute(const char* str);
	void setAMPM(const char* str);
	int getTimeInMinutes() const;
}; // class Time
#endif
