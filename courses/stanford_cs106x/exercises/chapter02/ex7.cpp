/*
 * Function: Sqrt
 * ---------------
 * An implementation of the `sqrt` in the <cmath.h> using successive approximation.
 * Caveat: This function only works for integers that do have an integer square root.
 * For whatever else, say 7 or 19, it gets stuck.
 */

#include <iostream>
using namespace std;

double Sqrt(double number) {
  double guess = number / 2;
  while(true) {
    if (guess == number / guess) return guess;

    guess = (guess + number / guess) / 2;
  }
}

int main() {
  cout << "Sqrt of 4 is " << Sqrt(4) << endl;
  cout << "Sqrt of 9 is " << Sqrt(9) << endl;
  cout << "Sqrt of 81 is " << Sqrt(81) << endl;
  cout << "Sqrt of 256 is " << Sqrt(256) << endl;
  cout << "Sqrt of 7 is " << Sqrt(7) << endl;
}
