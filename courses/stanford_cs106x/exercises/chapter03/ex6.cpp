/*
 * Function: acronym(str)
 * -----------------------
 * Return acronym formed from the string passed
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string acronym(string str)
{
  int N  = str.length();
  if (N == 0) return str;

  string acr(1, toupper(str[0]));
  for (int i = 1; i < N; i++) {
    if (!isalpha(str[i-1]) && isalpha(str[i])) {
      acr += toupper(str[i]);
    }
  }

  return acr;
}

int main()
{
  string scuba = "self-contained underwater breathing apparatus";
  string aids = "Acquired Immune Deficiency Syndrome";

  cout << " Acronym for " << scuba << " is " << acronym(scuba) << endl;
  cout << " Acronym for " << aids << " is " << acronym(aids) << endl;
  return 0;
}
