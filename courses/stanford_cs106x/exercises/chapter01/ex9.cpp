/*
 * File: ex9.cpp
 * -------------
 * Reads in an integer and displays its prime factorization.
 * Input: 60
 * Output: 2 x 2 x 3 x 5
 */

#include <iostream>
using namespace std;

int main()
{
  cout << "This program factors a number." << endl;
  cout << "Enter number to be factored: ";
  int number;
  cin >> number;

  int base = 2; // smallest prime
  while (true) {
    if (number % base == 0) {
      cout << base << " x ";
      number /= base;
    } else base += 1;

    // When base equals the last factor prime
    if (base == number) {
      cout << base << endl;
      break;
    }
  }

  return 0;

}
