// rewrite exercise 1.9
#include <iostream>

int main()
{
  int sum = 0;
  for (int i = 50; i <= 100; ++i)
    sum += i;

  std::cout << "The sum of 50 to 100 inclusive is "
            << sum << std::endl;

  for (int val = 10; val >= 0; --val) {
    std::cout << "val is now " << val << std::endl;
  }

  return 0;
}
