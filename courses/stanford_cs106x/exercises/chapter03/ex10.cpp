/*
 * Function: replaceAll(string str, char c1, char c2)
 * --------------------------------------------------
 * Replce very occurrance of c1 with c2 in str and return that new string.
 * `str' is left unmodified.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string replaceAll(string str, char c1, char c2)
{
  int N = str.length();
  string rep;

  for (int i = 0; i < N; ++i) {
    if (str[i] != c1) rep += str[i];
    else rep += c2;
  }
  return rep;
}

// Overloading; replace (sub)string instead
// The key is to remember where the last replacement starts and ends
string replaceAll(string str, string s1, string s2)
{
  int M = s1.length();
  string rep;
  int next = 0;
  int prev = 0;
  while (str.find(s1, next) != string::npos) {
    next = str.find(s1, next);
    if (prev == 0) rep += str.substr(0, next);
    else rep += str.substr(prev, next - prev);
    rep += s2;
    next += M;
    prev = next;
  }

  return rep;
}


int main()
{
  string word = "nannies";
  cout << "Replace all 'n' with 'd' in " << word << " becomes " << replaceAll(word, 'n', 'd') << endl;

  string stc = "Learn cpp cpp cpp and cpp";
  cout << "Replace all 'cpp' with 'rust' " << "in " << stc
       << " becomes " << replaceAll(stc, "cpp", "rust") << endl;
  return 0;

}
