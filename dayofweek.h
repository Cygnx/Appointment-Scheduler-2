#ifndef dayofweekH
#define dayofweekH

using namespace std;

class DayOfWeek
{
  char monthName[10];
  int month;
  int day;
  char dayName[10];
public:
  DayOfWeek(int mo, int d);
  friend ostream& operator<< (ostream&, const DayOfWeek&);
  void read();
}; // class DayOfWeek
//---------------------------------------------------------------------------
#endif

