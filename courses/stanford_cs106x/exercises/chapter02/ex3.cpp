/*
 * Function: roundToNearestInt.cpp
 * -------------------------------
 * Rounds the input floating-point number x to the nearest integer.
 */

#include <iostream>
using namespace std;

double roundToNearestInt(double input)
{
  if (input >= 0) return (int) (input + 0.5);
  else return (int) (input - 0.5);
}

int main()
{
  double input;
  cout << "Enter a floating-point number: ";
  cin >> input;
  cout << "Rounded: " << roundToNearestInt(input) << endl;
  return 0;
}
