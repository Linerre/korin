/*
 * Problem 6: Modify the code for `GetInteger` to create a function
 * `GetReal` that reads a real number from the user.
 * ------------------------------------------------------------
 */

#include <iostream>
#include <sstream>
using namespace std;

string GetLine()
{
  string result;
  getline(cin, result);
  return result;
}

int GetReal()
{
  while(true) {
    stringstream converter;
    converter << GetLine();
    double result;
    if (converter >> result) {
      char remaining;
      if (converter >> remaining) // Something's left, input invalid
        cout << "Unexpected character: " << remaining << endl;
      else
        return result;
    } else
      cout << "Please enter an integer: " << endl;

    cout << "Retry: ";
  }
}

int main()
{
  double real = GetReal();
  cout << "You entered a real number: " << real << endl;
  return 0;
}
