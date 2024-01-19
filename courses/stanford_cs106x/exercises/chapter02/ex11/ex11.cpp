#include <iostream>
#include "calendar.h"

using namespace std;

int main() {
  int year = 2024;
  Month month = Month::January;
  Month next = Month::Feburay;
  cout << "2024 is a leap year? (1 for yes and 0 for no): " << isLeapYear(year) << endl;
  cout << "Jan has : " << daysInMonth(month, year) << " days" << endl;
  cout << "Feb has : " << daysInMonth(next, year) << " days" << endl;
  cout << "Calling monthToString(month) gets: " << monthToString(month) << endl;
  cout << "Calling mToString(month) gets: " << mToString(next) << endl;
  return 0;
}
