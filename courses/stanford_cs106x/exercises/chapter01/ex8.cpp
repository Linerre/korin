/*
 * File: ex8.cpp
 * -------------
 * Reads in an integer and displays the digits in reverse order
 */

#include <iostream>
using namespace std;

int main()
{
  cout << "This program reverses the digits in an integer." << endl;
  cout << "Enter a positive integer: ";

  int input;
  cin >> input;
  int output = 0;
  while (input / 10 >= 1) {
    int digit = input % 10;
    input /= 10;
    output *= 10;               // move the digit one order up
    output += digit;
  }

  // Handle the last digit
  output = output * 10 + input;

  cout << "The reversed integer is " << output << endl;
  return 0;
}
