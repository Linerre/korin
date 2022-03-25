#include <iostream>

int main()
{
  int sum = 0;
  for (int i = -100; i <= 100; ++i)
    sum += i;

  std::cout << "The final value of sum is " << sum << std::endl;
  // expected: 0
  return 0;
}
