#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const int COLUMN_WIDTH = 20;
  cout << setfill('-') << setw(COLUMN_WIDTH) << "" << setfill(' ');
  // "" tells cout to print nothing but the dashes, i.e. padded up to 20 dashes
  cout << endl;
  cout << "NEW STUFF";
  return 0;
}
