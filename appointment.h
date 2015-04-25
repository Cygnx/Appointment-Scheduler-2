
#ifndef appointmentH
#define appointmentH

#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
public:
  Appointment();
	Appointment(const char*);
  ~Appointment();
  friend ostream& operator<< (ostream&, const Appointment&);
	friend istream& operator>>(istream &is, Appointment &a);
	char* getSubject() const;
  void read();
  bool operator== (const Appointment&) const; 
  bool compareSubject(const char*) const;
  Appointment& operator= (const Appointment&);
}; // class Appointment

#endif
