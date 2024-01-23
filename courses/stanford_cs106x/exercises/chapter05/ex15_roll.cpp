/*
 * Function: roll(n,k)
 * --------------------
 * Rotate the top n elements of a stack by k positions, where the
 * general direction of the rotation is toward the top of the stack.
 */

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void roll(stack<char> & stk, int n, int k);
string error(string msg);

int main()
{
  stack<char> stk;
  stk.push('A');
  stk.push('B');
  stk.push('C');
  stk.push('D');
  roll(stk, 3, 2);

  cout << "Stack now becomes: " << endl;
  while (!stk.empty()) {
    cout << "|" << stk.top() << "|" << endl;
    stk.pop();
  }
  cout << "---" << endl;
}

void roll(stack<char> & stk, int n, int k)
{
  if (n < 0 || k < 0 || n > (int)stk.size()) error("roll: argument out of bound");
  if (k % n == 0) return;       // No change after rotation

  stack<char> rota;             // stack for element to be rotated
  stack<char> rest;             // stack for rest elements of next round rotation

  int r = k > n ? k % n : k;    // Rotate r times where r < n

  for (int j = 0; j < r; ++j) {
    // Rotate
    for (int i = 0; i < n; ++i) {
      char top = stk.top();
      if (i == 0) {
        rota.push(top);
        stk.pop();
      } else {
        rest.push(top);
        stk.pop();
      }
    }

    // Update stk
    stk.push(rota.top());
    rota.pop();
    while(!rest.empty()) {
      stk.push(rest.top());
      rest.pop();
    }
  }

  return;
}

string error(string msg) {
  cout << "ERROR: " << msg << endl;
  exit(EXIT_FAILURE);
}
