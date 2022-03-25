#include <iostream>

int main()
{
  int sum = 0;
  int val;

  std::cout << "Enter 5 random integers and hold Ctrl-D to finish: " << std::endl;

  while (std::cin >> val) {
    sum += val;
  }

  std::cout << "The sum of these integers are " << sum << std::endl;
  return 0;
}
