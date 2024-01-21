/*
 * File: ex1.cpp
 * -------------
 * Displays a table of trigonometric sines and cosines.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  // Header
  cout << " theta | sin(theta) | cos(theta) |" << endl;
  cout << setfill('-') << setw(6) << "" << "-+"
       << setw(11) << "" << "-+"
       << setw(11) << "" << "-+" << setfill(' ') << endl;
  // Body
  for (double i = -90; i <= 90; i += 15) {
    cout << setw(5) << defaultfloat << i << setw(3) << "|" // left col
         << setw(11) << fixed << setprecision(7) << sin(i) << setw(2) << "|" // middld col
         << setw(11) << fixed << setprecision(7) << cos(i) << setw(2) << "|" << endl; // middld col
  }
  return 0;
}
