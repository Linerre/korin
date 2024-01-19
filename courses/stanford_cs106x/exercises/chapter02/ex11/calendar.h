/*
 * File: calendar.h
 * ----------------
 * Exports a type `Month` and the following three functions:
 * 1. daysInMonth
 * 2. isLeapYear
 * 3. monthToString
 */
#ifndef _calendar_h
#define _calendar_h
#include <string>
using std::string;

enum Month {
	January, Feburay, March, April,
	May, June, July, August,
	September, October, November, December,
};

int daysInMonth(Month month, int year);

bool isLeapYear(int year);

string monthToString(Month month);
string mToString(Month month);

#endif
