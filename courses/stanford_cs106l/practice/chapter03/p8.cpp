/*
 * Problem 10: Write a function HasHexLetters that accpets an int and
 * returns whether or not that integer's hexadecimal representation
 * contains letters.
 * Requirement: loops are _not_ allowed
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void HasHexLetters()
{
  cout << "Please enter an integer: ";
  int input;
  cin >> input;
  cout << "Input from cin: " << input << endl;

  stringstream buf;
  buf << hex << input;

  /*
   * Try to read it back to an integer.  If it contains any letters this would fail.
   */
  int output;
  buf >> dec >> output;

  /*
   * For single letter representations such as F (15)
   */
  if (buf.fail()) {
    cout << "With letters" << endl;
    return;
  }


  /*
   * For with-letter representations that start with a digit, keep checking it
   */

  char remaining;
  buf >> remaining;
  if (!buf.fail())
    cout << "With letters" << endl;
  else
    cout << "Without letters" << endl;
}

int main()
{
  HasHexLetters();
  return 0;
}
