/*
 * File: ex6.cpp
 * -------------
 * Reads in a list of integers until 0 (sentinel) and displays the
 * largest value as well as the second largest value in the list.
 */

#include <iostream>
using namespace std;

const int SENTINEL = 0;
void TwoLargestsGiven()
{
  int input;
  int largest = 0;
  int secondLargest = 0;
  while(true) {
    cout <<  " ? ";
    cin >> input;
    if (input > largest) {
      secondLargest = largest;
      largest = input;
    }
    if (input == SENTINEL) {
      cout << "The largest value was " << largest << "." << endl;
      cout << "The second largest value was " << secondLargest << "." << endl;
      return;
    }
  }
}


int main()
{
  cout << "This program finds the largest integer in a list." << endl;
  cout << "Enter 0 to signal the end of the list." << endl;
  TwoLargestsGiven();
  return 0;
}
