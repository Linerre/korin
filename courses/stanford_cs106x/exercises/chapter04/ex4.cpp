/*
 * File: ex4.cpp
 * --------------
 * Read in the file `Lear.txt' and count its lines, words and characters
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
  ifstream txt;
  txt.open("Lear.txt");
  int lines = 0;
  int words = 0;
  int chars = 0;
  string line;
  while (true) {
    getline(txt, line);
    if (txt.fail()) break;
    lines++;

    int n = line.size();
    chars += (n + 1);           // all characters of the line plus the newline `\n'
    words++;                    // If there's a line, there must be at least 1 word
    for (int i = 0; i < n; ++i) {
      if (isspace(line[i]) && !isspace(line[i+1])) {
        words++;
      }
    }
  }
  txt.close();

  cout << "Chars: " << chars << endl;
  cout << "Words: " << words << endl;
  cout << "Lines: " << lines << endl;
  return 0;
}
