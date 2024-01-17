/*
 * Funtion: isPerfect
 * ------------------
 * Decide if a given integer is a perfect number (the sum of its proper divisors).
 */

#include <iostream>
using namespace std;

bool isPerfect(int number) {
  if (number == 1)
    return false;

  int base = 1;
  int sum = 0;
  while (true) {
    if (number % base == 0)
      sum += base;

    base++;
    if (base == number) break;
  }

  return sum == number;
}

int main() {
  for (int i=1; i<=9999; i++) {
    if (isPerfect(i))
      cout << i << " is a perfect number." << endl;
  }
  return 0;
}
