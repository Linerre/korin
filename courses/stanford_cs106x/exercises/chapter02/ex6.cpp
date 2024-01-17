/*
 * Function: isPrime
 * -----------------
 * Check if a given integer is prime.
 */

#include <iostream>
using namespace std;

bool isPrime(int number) {
  if (number == 1) return false;

  // No number can be divided by larger-than-half-of-it
  for (int i = 2; i <= number / 2; i++)
    if (number % i == 0) return false;

  return true;
}

int main() {
  cout << "Prime numbers between 1 and 100: " << endl;
  for (int i=1; i<=100; i++) {
    if (isPrime(i))
      cout << i << endl;
  }
}
