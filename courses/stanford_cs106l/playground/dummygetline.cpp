#include <iostream>
using namespace std;

int main()
{
  int dummyInt;
  string dummyString;
  cin >> dummyInt;
  getline(cin, dummyString);

  cout << "Dummy String: " << dummyString << endl; // empty or the `/n' character
  return 0;
}
