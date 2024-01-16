/*
 * Problem 7: Using the code for GetInteger and the boolalpha stream
 * manipulator, write a function GetBoolean that waits for the user to
 * enter “true” or “false” and returns the corresponding boolean
 * value.
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

bool GetBoolean()
{
  while(true) {
    stringstream converter;
    converter << GetLine();
    bool result;
    if (converter >> boolalpha >> result) { // Must use manupilator here
      char remaining;
      if (converter >> remaining) // Something's left, input invalid
        cout << "Unexpected character: " << remaining << endl;
      else
        return result;
    } else
      cout << "Please enter 'true' or 'false': " << endl;

    cout << "Retry: ";
  }
}

int main()
{
  cout << "Please enter 'true' or 'false': ";
  bool result = GetBoolean();
  cout << "You entered: " << boolalpha << result << endl;
  return 0;
}
