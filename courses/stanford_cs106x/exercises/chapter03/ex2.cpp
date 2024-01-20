/*
 * Function: trim(str)
 * ------------------
 * Remove whitespace characters from the beginning and end of str.
 */

#include <iostream>
#include <cctype>
using namespace std;

string trim(string str)
{
  int N = str.length();
  string trimed = "";
  int start = 0;
  int end = N - 1;
  for (int i = 0; i < N; ++i) {
    if (!isspace(str[i])) {
      start = i;
      break;
    }
  }

  for (int i = N - 1; i > 0; --i) {
    if (!isspace(str[i])) {
      end = i;
      break;
    }
  }

  for (int i = start; i <= end; ++i) trimed += str[i];
  return trimed;
}

int main()
{
  string maltext = "   \t I'm a sentence.  ";
  cout << "'" << maltext << "'" << " trimed to "
       << "'" << trim(maltext) << "'" << endl;
  return 0;
}
