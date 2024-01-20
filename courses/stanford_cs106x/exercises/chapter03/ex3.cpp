/*
 * Function: substr(str, pos, n)
 * ----------------------------
 * A free fn that returns the substring of `str' beginning at position `pos' and
 * containing at most `n' characters, especially:
 * 1. When `n' is missing or greater than the length of `str', the substring extends
 * through the end of the original `str'; and
 * 2. When `pos' is greater than the length of `str', the fn returns `error'
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string error(string msg) {
  cout << "ERROR: " << msg << endl;
  exit(EXIT_FAILURE);
}

string substr(string str, int pos, int n)
{
  int N = str.length();
  if (pos > N) return error("Substring starts outside the original.");

  string sub = "";
  if (n > N) {
    for (int i = pos; i < N; ++i) {
      sub += str[i];
    }
  } else {
    for (int i = pos; i < n; ++i) {// n characters does not include n due to 0-index
      sub += str[i];
    }
  }
  return sub;
}

string substr(string str, int pos)
{
  int N = str.length();
  if (pos > N) return error("Substring starts outside the original.");

  string sub = "";
  for (int i = pos; i < N; ++i) {
    sub += str[i];
  }

  return sub;
}

int main()
{
  string chain = "Solana";
  cout << "On " << chain << " the native token is " << substr(chain, 0, 3) << endl;

  cout << substr(chain, 0, 3) << " is used for chain " << substr(chain, 0, 8) << endl;
  cout << "Repeat: " << substr(chain, 0) << endl;

  cout << "Asking for the 8th character of " << chain << " will cause error!" << endl;

  substr(chain,8);
  return 0;
}
