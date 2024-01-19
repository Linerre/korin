/*
 * File: p8.cpp
 * -------------
 * Add NOT_A_COLOR special value.
 */

#include <iostream>

using namespace std;

enum Color {
 #define DEFINE_COLOR(color, opposite) color, // Name followed by comma
 #include "color.h"
 #undef DEFINE_COLOR
  NOT_A_COLOR,
 };

string ColorToString(Color c) {
 switch(c) {
 /*
  * Convert something of the form DEFINE_COLOR(color, opposite)
  * into something of the form 'case color: return "color"';
  */
 #define DEFINE_COLOR(color, opposite) case color: return #color;
 #include "color.h"
 #undef DEFINE_COLOR

 default: return "NOT_A_COLOR";
 }
}

Color StringToColor(string c) {
  switch(c) {
    /*
     * Convert a string to the corresponding color
     */
    #
  }
}

int main() {
  return 0;
}
