/*
 * File: ex9.cpp
 * ----------------------------
 */

#include <iostream>
using namespace std;

/*
 * Function: permutations(n,k)
 * ----------------------------
 * Compute permutatons of P(n,k) without using factorials.
 * P(n,k) = n!/(n-k)! = n * (n-k+1)
 */
int permutations(int n, int k) {
  int result = 1;
  for (int i=0; i<k; i++)
    result *= (n - i);

  return result;
}

int main() {
  int deck = 52;
  int cards = 3;
  cout << "Two cards from a deck results in " << permutations(deck, cards) << " permutations." << endl;
}
