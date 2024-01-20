/*
 * Function: rmDblLtrs(str)
 * -----------------------
 * Remove double letters from the given string.  For example:
 * Input: bookkeeper
 * Output: bokeper
 */

#include <iostream>
#include <string>

using namespace std;

string rmDblLtrs(string str)
{
  int N = str.length();
  if (N == 0) return str;

  string rmed = "";
  for (int i = 1; i < N; ++i) {
    if (str[i-1] != str[i]) {
      rmed += str[i-1];
      if (i == N - 1) rmed += str[i];
    }
  }

  return rmed;
}


int main()
{
  string word = "bookkeeper";
  string w2 = "committe";
  cout << "Result: " << rmDblLtrs(word) << endl;
  cout << "Result: " << rmDblLtrs(w2) << endl;
}
