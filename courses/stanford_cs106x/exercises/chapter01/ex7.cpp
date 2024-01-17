/*
 * File: ex7.cpp
 * -------------
 * Reads in a list of integers until 0 and calculate the average.
 */

#include <iostream>
using namespace std;

const int SENTINEL = -1;

int main()
{
  cout << "This program calculates the average of a list of numbers." << endl;
  cout << "Use " << SENTINEL << " to signal the end." << endl;
  int total = 0;
  int count = 0;
  while (true) {
    int value;
    cout << " ? ";
    cin >> value;
    if (value == SENTINEL) break;
    total += value;
    count++;
  }
  cout << "The total is " << total << endl;
  cout << "The list has " << count << " values" << endl;
  cout << "The average is (integer part only) " << total / count << endl;
  return 0;
}
