/*
 * Read in a positive integer N and calculates the sum of first N odd
 * integers.  For example: input N = 4, output sum = 16 (1+3+5+7)
 * For sake of simplicity, I just handle a small range of N
 */

#include<iostream>

int FirstNoddSum(int first)
{
  int sum = 0;
  for (int i=0; i<first; ++i) {
    sum += 2 * i + 1;
  }
  return sum;
}

int main()
{
  std::cout << "Please enter a positive integer N (0 <= N <= 10000): ";
  int N;
  std::cin >> N;
  int result = FirstNoddSum(N);
  std::cout << "The result sum is: " << result << std::endl;
  return 0;
}
