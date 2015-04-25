
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

int Time::getTimeInMinutes() const
{
	return hour * 60 + minute;
}
void Time::read()
{
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  char *ptr = strtok(NULL, ",");

  if(strchr(ptr, 'P') && hour != 12)
    hour += 12;
} // read()
void Time::setHour(const char* str)
{
	int hour_ = atoi(str);
		if (strlen(str) < 3 && strlen(str) > 0 && atoi(str) > 0&& atoi(str) <= 12)
			hour = hour_;
		else
		{
			hour = -1;
			cout<< "Hour must be between 1 and 12." << endl;
			cout<< "Format of time is hh:mm PM or hh:mm AM.\n" << endl;
		}//if hour correct, else error
}//setHour()
void Time::setMinute(const char* str)
{
	int length = strlen(str);
	int minute_ = atoi(str);
	if (minute_>=0 && minute_<=59 && length == 2)
		minute = minute_;
	else if(length == 2)
	{
		minute = -1;
		cout<< "Minutes must be between 00 and 59." << endl;
		cout<< "Format of time is hh:mm PM or hh:mm AM.\n" << endl;
	}//if minute correct, else error
	else
	{
		minute = -1;
		cout<< "Your time is invalid." << endl;
		cout<< "Format of time is hh:mm PM or hh:mm AM.\n" << endl;
	}
}//setHour()
void Time::setAMPM(const char* str)
{
	if(((strstr (str, "PM") || strstr (str, "AM"))) && strlen(str) < 3)
	{
		if(strchr(str, 'P') && hour != 12)
		{
			hour += 12;
		}
	}//if AM or PM, else error
	else 
	{
		hour = -1;
		cout<< "The AM/PM is invalid." << endl;
		cout<< "Format of time is hh:mm PM or hh:mm AM.\n" << endl;
	}
}//setAMPM()

istream& operator>>(istream &is, Time &t) {
	char s[80];
	char *ptr;
	do {
		is.getline(s, 80);
    ptr = strtok(s, ": \t");
		if(ptr != NULL)
			t.setHour(ptr);
		else
			t.setHour("");
		if (t.hour == -1 || ptr == NULL) {
			cout << "Time >> ";
		continue;
		}
		ptr = strtok(NULL, " \t");
		if(ptr != NULL)
			t.setMinute(ptr);
		else
			t.setMinute("");
		if (t.minute == -1 || ptr == NULL) {
			cout << "Time >> ";
			continue;
		}
		
		ptr = strtok(NULL, "\n");
		
		if(strlen(ptr) > 2)
		{
			while(*ptr == ' ' || *ptr == '\t')
				ptr+=1;
		} 
		
		if(ptr != NULL)
			t.setAMPM(ptr);
		else
				t.setAMPM("");
		if (t.hour == -1) {
			cout << "Time >> ";
			continue;
		}//loop while need correct time
		break;
	} while (true);
	return is;
}//Time operator>> overload

ostream& operator<<(ostream &os, const Time &t) 
{
  os << setw(2) << setfill('0') << right << t.hour << ":" << setw(2) << t.minute
    << " " << setfill(' ');
  return os;
}//Time operator<< overload()
