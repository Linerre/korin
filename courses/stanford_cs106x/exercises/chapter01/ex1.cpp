/*
 * Exercise 1: Celsius to Fahrenheit converter
 */

#include <iostream>
using namespace std;

double CToF(double celsius)
{
  return celsius * 9 / 5 + 32;
}

int main()
{
  cout << "Enter a Celsius degree: ";
  double celsius;
  cin >> celsius;

  double result = CToF(celsius);

  cout << "Converted to Fahrenheit: " << result << endl;
}
