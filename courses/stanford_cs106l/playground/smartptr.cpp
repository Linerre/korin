#include <iostream>
using namespace std;
void f()
{
int *x = new int(4);
cout << *x << endl;
int *y = x;
*y = 8;
cout << *x << endl;
delete x;
}

int main()
{
  f();
  return 0;
}
