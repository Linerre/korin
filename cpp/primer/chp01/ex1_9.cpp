#include <iostream>

int main()
{
  int sum = 0;
  int val = 50;
  while ( val <=100 ) {
    sum += val;
    val += 1;
  }
  std::cout << "The sum of 50 to 100 inclusive is "
            << sum << std::endl;
  // The sum of range 50-100 is 3825
  return 0;
}
