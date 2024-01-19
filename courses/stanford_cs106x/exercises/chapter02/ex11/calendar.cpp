/*
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include "calendar.h"
using namespace std;

int daysInMonth(Month month, int year) {
  switch (month) {
  case April:
  case June:
  case September:
  case November:
    return 30;
  case Feburay:
    return (isLeapYear(year)) ? 29 : 28;
  default:
    return 31;
  }
}

bool isLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0))
    || (year % 400 == 0);
}

/*
 * The normal version using switch statement
 */
string monthToString(Month m) {
  switch (m) {
  case January: return "January";
  case Feburay: return "Feburay";
  case March: return "March";
  case April: return "April";
  case May: return "May";
  case June: return "June";
  case July: return "July";
  case August: return "August";
  case September: return "September";
  case October: return "October";
  case November: return "November";
  case December: return "December";
  default: return "Unknown";
  }
}

/*
 * Abnormal version using X macros
 */
string mToString(Month m) {
  switch(m) {
    #define MONTH(m) case m: return #m;
    #include "months.h"
    #undef MONTH

  default: return "Unknown";
  }
}
