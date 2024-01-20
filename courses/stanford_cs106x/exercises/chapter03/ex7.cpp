/*
 * Function: removeChars(str, remove)
 * ----------------------------------
 * Remove all occurrences of chars appearing in `remove' from `str'.  This fn return
 * a new string without modifying the original one.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeChars(string str, string remove)
{
  int N = str.length();
  string left = "";

  for (int i = 0; i < N; ++i) {
    string letter(1, str[i]);
    // find() returns the pos of first found char or `npos'
    if (remove.find(letter) == string::npos) left += str[i];
  }

  return left;
}

// Just one of the many ways for the task
void removeCharsInPlace(string & str, const string & remove)
{
  int N = str.length();
  string left = "";

  for (int i = 0; i < N; ++i) {
    string letter(1, str[i]);
    // find() returns the pos of first found char or `npos'
    if (remove.find(letter) == string::npos) left += str[i];
  }
  str.clear();
  str = left;
}

int main()
{
  string org = "counterrevolutionaries";
    cout << "'" << org << "'" << " after removing all vowels becomes "
       << removeChars(org, "aeiou") << endl;

    cout << "After removing vowels in place, the original string now is ";
    removeCharsInPlace(org, "aeiou");

    cout << org << endl;
  return 0;
}
