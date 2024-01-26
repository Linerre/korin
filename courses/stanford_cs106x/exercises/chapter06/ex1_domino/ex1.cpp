#include <iostream>
#include <string>
#include "domino.h"

using namespace std;

int main()
{
  cout << "A full set of domino: " << endl;
  for (int i = 0; i <= 6; ++i) {
    for (int j = 0; j <= i; ++j) {
      Domino domi(i, j);
      cout << domi.toString() << endl;
    }
  }
  return 0;
}
