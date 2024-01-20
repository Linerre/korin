/*
 * Function: addCommas(string digits)
 * ----------------------------------
 * Add commas to separate the digitis into groups of three.  For example,
 * Input: 1000000
 * Ouput: 1,000,000
 */

#include <iostream>
#include <string>

using namespace std;

string addCommas(string digits)
{
  int N = digits.size();
  if (N <= 3) return digits;

  // Start with the end, relative position will not change
  for (int i = N - 3; i > 0; i -= 3) {
    digits.insert(i, ",");
  }
  return digits;

}

int main()
{
  while (true) {
    string digits;
    cout << "Enter a number: ";
    getline(cin, digits);
    if (digits == "") break;
    cout << addCommas(digits) << endl;
  }
  return 0;
}
