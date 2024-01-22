/*
 * File: ex6.cpp
 * -------------
 * Using collections to implement the sieve of Eratosthenes algorithm.
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool is_prime(int n)
{
  if (n == 2) return true;

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) return false;
  }

  return true;
}

int main()
{
  int N;
  set<int> primes;
  set<int> composites;

  cout << "Enter an integer: ";
  cin >> N;
  for (int i = 2; i <= N; ++i) {
    if (auto search = composites.find(i); search != composites.end()) continue;

    if (is_prime(i)) {
      primes.insert(i);
      int m = 2;
      while (m * i <= N) {
        if (auto search = composites.find(m * i); search != composites.end())
          {
            cout << m * i << " already in comp skipping ..." << endl;
            m++;
            continue;
          }
        cout << "going to insert " << m * i << " to comp ..." << endl;
        composites.insert(m * i);
        m++;
      }
    }
  }

  int pnum = primes.size();
  int cnum = composites.size();
  cout << "There are " << pnum << " primes and " << cnum << " composites between 2 and " << N << endl;
  cout << "Primes: " << endl;
  cout << "{";
  for_each (primes.begin(), primes.end(), [](int const & p) { cout << p << ", ";});
  cout << "}" << endl;

  return 0;
}
