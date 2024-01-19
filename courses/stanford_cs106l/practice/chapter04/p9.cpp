/*
 * File: p9.cpp
 * ------------
 * Accept a string and return the corresponding color.
 * To be honest, such code sucks.  I cant even imagine in what situations do
 * I need to write this piece of shit! (Of course, for exercising purposes here)
 */

#include <iostream>
using namespace std;

enum Color {
 #define COLORS(color) color, // Name followed by comma
 #include "colors.h"
 #undef COLORS
  NOT_A_COLOR,
};

Color StringToColor(string colstr) {
#define COLORS(col) if (colstr == #col) return col;
#include "colors.h"
#undef COLORS
  return NOT_A_COLOR;
}

int main() {
  string color1 = "Green";
  string color2 = "Cyan";
  string color3 = "gree";
  string color4 = "Olive";

  cout << "'Green' is color: " << StringToColor(color1) << endl;
  cout << "'Cyan' is color: " << StringToColor(color2) << endl;
  cout << "'gree' is color: " << StringToColor(color3) << endl;
  cout << "'Olive' is color: " << StringToColor(color4) << endl;
  return 0;
}
