/*
 * File: ex5.cpp
 * -------------
 * Reads in a list of integers until 0 (sentinel) and displays the
 * largest value in the list.
 */

#include <iostream>
using namespace std;

const int SENTINEL = 0;

int LargestGiven()
{
  int input;
  int largest = 0;
  while(true) {
    cin >> input;
    if (input >= largest) largest = input;
    if (input == SENTINEL) return largest;
  }
}


int main()
{
  cout << "This program finds the largest integer in a list." << endl;
  cout << "Enter 0 to signal the end of the list." << endl;
  cout <<  " ? ";
  int result = LargestGiven();
  cout << "The largest value was " << result << "." << endl;
  return 0;
}
