
#include <cstring>
#include <iostream>
#include <iomanip>
#include "appointment.h"

using namespace std;

Appointment::Appointment() : subject(NULL), location(NULL)
{
}  // Appointment()
Appointment::Appointment(const char *subject_): location(NULL)
{
	subject = new char[strlen(subject_) + 1];
	strcpy(subject, subject_);
}  // Appointment()

Appointment::~Appointment()
{
  if(subject)
    delete [] subject;	
  if(location)
    delete [] location;
} // ~Appointment()

char* Appointment::getSubject() const
{
	return subject;
}
bool Appointment::compareSubject(const char *s) const
{
  return strcmp(subject, s) == 0;
}  // compareSubject()
bool Appointment::operator== (const Appointment &s) const
{
  return strcmp(subject, s.subject) == 0;
}
istream& operator>>(istream &is, Appointment &a) 
{
	char ptr[80];
	cout<< "Subject >> ";
	is.getline(ptr, 80);
	a.subject = new char[strlen(ptr)+1];
	strcpy(a.subject, ptr);
	cout<< "Location >> ";	
	is.getline(ptr, 80);
	a.location = new char[strlen(ptr)+1];
	strcpy(a.location, ptr);
	cout << "Start time >> ";
	is >> a.startTime;
	cout << "End time >> ";
	is >> a.endTime;
	int sTime, eTime;
	sTime = (int)a.startTime.getTimeInMinutes();
	eTime = (int)a.endTime.getTimeInMinutes();
	if (sTime > eTime)
	{	
		cout << "Start time is later than end time!" << endl;
		cout << "Start time >> ";
		is >> a.startTime;
		cout << "End time >> ";
		is >> a.endTime;
	}	
	return is;
}
void Appointment::read()
{
  char *ptr;

  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, ",");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // read() 

Appointment& Appointment::operator= (const Appointment &rhs)
{
  if(this == &rhs)
    return *this;

  startTime = rhs.startTime;
  endTime = rhs.endTime;

  if(subject)
  {
    delete [] subject;
    subject = NULL;
  }  // if subject already set

  if(location)
  {
    delete [] location;
    location = NULL; 
  } // if location already set

  if(rhs.subject)
  {
    subject = new char[strlen(rhs.subject) + 1];
    strcpy(subject, rhs.subject);
  }  // if rhs has a subject

  if(rhs.location)
  {
    location = new char[strlen(rhs.location) + 1];
    strcpy(location, rhs.location);
  } // if rhs has a location

  return *this;
} // operator=


ostream& operator<< (ostream& os, const Appointment &a)
{
  os << a.startTime << a.endTime;
  os << setw(15) << left << a.subject << " " << a.location << endl;
  return os;
}//Appointment operator<< overload
