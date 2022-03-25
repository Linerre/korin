#include <iostream>

int main()
{
  int sum = 0;
  int val = 50;
  while ( val <=100 ) {
    val += 1;
    sum += val;
  }
  std::cout << "The sum of range 55-100 is "
            << sum << std::endl;
  // The sum of range 55-100 is 3876
  return 0;
}
