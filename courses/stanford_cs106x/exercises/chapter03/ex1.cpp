/*
 * File: ex1.cpp
 * -------------
 * endsWith(str, suffix), where suffix can ba a char or a string
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

/*
 * Function: startsWith(str, prefix)
 * ---------------------------------
 * Check if str starts with the given prefix (string or a single character)
 * Note it copies the string while pass-by-reference also works.
 */
bool startsWith(string str, string prefix) {
  if (str.length() < prefix.length()) return false;
  for (int i = 0; i < prefix.length(); i++) {
    if (str[i] != prefix[i]) return false;
  }
  return true;
}

/*
 * Function: endsWith(str, suffix)
 * ------------------------------
 * Similar to startsWith but checks if str ends with given suffix.
 * I deliberately use reference to parameters here. Also it does NOT
 * handle cases intentionally.
 */
bool endsWith(const string & str, const string & suffix)
{
  int M = str.length();
  int N = suffix.length();
  if (M < N) return false;

  for (int i = 0; i < N; ++i) {
    if (suffix[N-1-i] != str[M-1-i]) return false;
  }
  return true;

}

int main()
{
  string course =  "Stanford CS106X";
  string code = "CS106X";
  cout << course << " ends with " << code << "?: "
       << boolalpha << endsWith(course, code) << endl;

  string word = "Rust";
  string letter = "t";
  cout << word << " ends with " << letter << "?: "
       << boolalpha << endsWith(word, letter) << endl;

  string cpu = "AMD 6800H";
  string end = "x";
  cout << cpu << " ends with " << end << "?: "
       << boolalpha << endsWith(cpu, end) << endl;
  return 0;
}
