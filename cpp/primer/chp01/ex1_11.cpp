#include <iostream>

int main()
{
  // NOTE: The biggest integers range this program supports is (+-) 2^32 - 1;
  std::cout << "Enter two integers separated by space: ";
  int start = 0, end =0;
  std::cin >> start >> end;

  std::cout << "Now the numbers between "
            << start << " and " << end
            << " (both inclusive) will be printed below:" << std::endl;
  while (start <= end) {
    std::cout << "The number in this turn is "
              << start << std::endl;
    ++start;
  }
  return 0;
}
