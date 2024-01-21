/*
 * File: ex2.cpp
 * -------------
 * The original exercise asks to find the longest line in a file
 * but I'm too lazy to create a file, so I'll just ask user to type in sentences.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
  string line = "";
  string sen = "";
  long unsigned len = 0;
  cout << "Enter sentences and hit return. Enter 0 to indiate the end: " << endl;
  while (true) {
    cout << " ? ";
    getline(cin, line);
    if (line.size() == 1) break;
    if (line.size() > len) {
      sen = line;
      len = line.size();
    }
  }
  cout << "Longest line: " << sen << endl;
  return 0;
}
