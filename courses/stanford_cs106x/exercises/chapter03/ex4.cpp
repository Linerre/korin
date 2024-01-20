/*
 * Function: capitalize(str)
 * ------------------------
 * Return capitalized `str' if it starts with a letter.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalize(string str)
{
  int N = str.length();
  // Empty string or that which starts with a digit will be returned as is
  if (N == 0) return str;
  if (isdigit(str[0])) return str;

  // toupper/tolower all return a char not a string
  // string cap = "";
  // cap += toupper(str[0]);
  string cap(1, toupper(str[0]));

  for (int i = 1; i < N; ++i) {
    cap += tolower(str[i]);
  }
  return cap;
}

int main()
{
  string BL = "BOOLEAN";
  string bl = "boolean";

  cout << BL << " is capitalized to " << capitalize(BL) << endl;
  cout << bl << " is capitalized to " << capitalize(bl) << endl;
  cout << "20rules" << " is capitalized to " << capitalize(string("20rules")) << endl;
}
