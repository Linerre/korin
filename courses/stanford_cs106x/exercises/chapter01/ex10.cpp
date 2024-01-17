/*
 * File: ex10.cpp
 * One Godel, Escher, Bach puzzle that accepts one positive integer n:
 * if n is equal to 1, end
 * if n is even, divide it by two
 * if n is odd, multiply it by three and add one
 */

#include <iostream>
using namespace std;

int main() {
  cout << "Enter a number: ";
  int number;
  cin >> number;
  while (true) {
    if (number == 1) break;

    if (number % 2 == 0) {
      cout << number << " is even, so I divide it by 2 to get " << number / 2 << endl;
      number /=2;
    } else {
      cout << number << " is odd, so I multiply it by 3 and add 1 to get " << number * 3 + 1 << endl;
      number = number * 3 + 1;
    }
  }

  return 0;
}
