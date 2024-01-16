/*
 * Problem 5: Using a `stringstream`, write a function that converts
 * an `int` into a `string`.
 * ------------------------------------------------------------
 * `intToString` is the solution and `main` is used for testing.
 */

#include <iostream>
#include <sstream>
using namespace std;

string interal_input(int input) {
  stringstream buf;
  buf << input;
  return buf.str();
}

void external_input()
{
  cout << "Please enter an integer: ";

  /*
   * See reader on page 36 on this `while` technique
   */
  while (true) {
    int usr_input;
    cin >> usr_input;
    if (!cin.fail()) {
      cout << "You entered int: " << usr_input << endl;
      stringstream buf;
      buf << usr_input;
      cout << "Converted to string: " << "\"" << buf.str() << "\"" << endl;
    } else break;
  }
  cout << "ERROR: You entered invalid integers. Possible valid part shown above" << endl;

}

int main()
{
  int internal = 10;
  cout << "Internal integer: " << internal << endl;
  cout << "Calling the `internal_input` to convert interal integer to string" << endl;
  string result = interal_input(internal);
  cout << "Integer " << internal << "now is string" << "\"" << result << "\"" << endl;

  cout << "Calling the `external_input` to convert user integer to string" << endl;
  external_input();

  return 0;
}
