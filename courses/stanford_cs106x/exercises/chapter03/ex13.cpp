/*
 * Function: creatOrdinalForm(n)
 * -----------------------------
 * Returns the ordinal form of number `n' as a string
 * Input: 21
 * Output 21st
 * Input: 11
 * Output: 11th
 */
#include <iostream>
#include <string>
using namespace std;

// Breaks the problem down into
// 1. n = X + 1/2/3 or
// 2. n = X + 11/12/13 or
// 3. n
string creatOrdinalForm(int n)
{
  if (n > 10) {
    for (int i = 11; i <= 13; ++i) {
      int left = n - i;
      if (left % 100 == 0 || left == 0)
        return to_string(n) + "th";
    }

    for (int i = 1; i <=3; ++i) {
      int left = n - i;
      if (left % 10 == 0) {
        if (i == 1) return to_string(n) + "st";
        else if (i == 2) return to_string(n) + "nd";
        else return to_string(n) + "rd";
      }
    }
  } else {
    if (n == 1) return to_string(n) + "st";
    else if (n == 2) return to_string(n) + "nd";
    else if (n == 3) return to_string(n) + "rd";
  }
  return to_string(n) + "th";
}

int main()
{
  while(true) {
    // string number;
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Ordinal form: " << creatOrdinalForm(number) << endl;
  }
  return 0;
}
