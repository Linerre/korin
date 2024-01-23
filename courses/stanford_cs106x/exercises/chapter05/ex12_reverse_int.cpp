/*
 * File: reverse_int.cpp
 * ---------------------
 * Use stack to reverse a sequence of intergers read from the console.
 * One number per line.
 */

#include <iostream>
#include <stack>
using namespace std;

int SENTINEL = 0;

int main()
{
  cout << "Enter a list of integers, ending with 0:" << endl;
  stack<int> nums;
  while (true) {
    int num;
    cout << " ? ";
    cin >> num;
    if(cin.fail() || num == 0) break;

    nums.push(num);
  }
  cout << "Those integers in reverse order are: " << endl;
  while(!nums.empty()) {
    cout << " " << nums.top() << endl;
    nums.pop();
  }
  return 0;
}
