
#include <iostream>
#include <iomanip>
#include "appointment.h"
#include "day.h"
#include "dayofweek.h"

using namespace std;

Day::Day() : apptCount(0)
{
} // Day()
Day::Day(const short mo, const short d) : apptCount(0)
{
	month = mo;
  day = d;
} // Day()
Day::~Day()
{
  for(int j = 0; j < apptCount; j++)
    delete  appts[j];
} // ~Day()
istream& operator>>(istream &is, Day &d) {
	d.appts[0] = new Appointment(); 
	is >> *(d.appts[0]);
	d.apptCount++;
	return is;
}
short Day::getMonth() const
{
	return month;
}
short Day::getDay() const
{
	return day;
}
int Day::compareDate(short mo, short d) const
{
  if(month == mo)
    return day - d;
  else
    return month - mo;
}

void Day::printAppts() const
{
  for(int j = 0; j < apptCount; j++)
    cout << *(appts[j]);
}  // printAppts()


void Day::printSubject(const char *s, bool &found) const
{
  for(int j = 0; j < apptCount; j++)
	{
		Appointment *temp = new Appointment(s);
			if(*(appts[j]) == *temp)
	//		if(appts[j]->compareSubject(s))
			{
				if(!found)
					cout << "Date                           Start End   Subject         "
						<< "Location\n";

				cout << *this;
				
				cout << *(appts[j]);
				found = true;
			} // if appts matched subject
		}
} // printSubject()


void Day::read()
{
  appts[apptCount] =  new Appointment;
  appts[apptCount++]->read();
} // read()


void Day::reset(short mo, short d)
{
  month = mo;
  day = d;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  apptCount = 0;
}  // setDate()


Day& Day::operator= (const Day &d)
{
  if(this == &d)
    return *this;

  for(int j = 0; j < apptCount; j++)
    delete  appts[j];

  day = d.day;
  month = d.month;
  apptCount = d.apptCount;

  for(int i = 0; i < apptCount; i++)
  {
    appts[i] = new Appointment();
    *appts[i] = *d.appts[i];
  }

  return *this;
}  // operator=
Day& Day::operator+= (const Day &d)
{
	appts[apptCount] = new Appointment();
	*(appts[apptCount]) = *(d.appts[0]);
   apptCount++;
	return *this;
}

ostream& operator<< (ostream &os, const Day &d) 
{
  DayOfWeek dayOfWeek(d.month, d.day);
  dayOfWeek.read();
  cout << dayOfWeek;
  return os;
}//Day operator<< overload
