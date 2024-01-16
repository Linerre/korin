/*
 * Problem 9: Triangle
 * ------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
using namespace std;

void DrawTriangle(int height, char symbol)
{
  for (int i = 0; i < height; ++i) {
    int pad = height - i - 1;
    cout << setfill(' ') << setw(pad) << ""          // left
         << setfill(symbol) << setw(2*i + 1) << ""   // symbol
         << setfill(' ') << setw(pad) << "" << endl; // right
  }
}

int main()
{
  cout << "Enter height and symbol, use space to separate them (i.e '3 #'): " << endl;

  int height;
  char symbol;
  cin >> height >> symbol;

  DrawTriangle(height, symbol);
  return 0;
}
