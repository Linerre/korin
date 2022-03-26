#include <iostream>

int main()
{
  int sum = 0;
  int val = 0;

  std::cout << "Enter random integers. " << std::endl;
  std::cout << "But the latter should be bigger than the former. " << std::endl;
  std::cout << "Press Enter and then Ctrl-D to terminate: " << std::endl;

  if (std::cin >> val) {//Make sure we have invalid data to process
    int curr_val = val;
    std::cout << "The first number is " << curr_val << std::endl;

    while (std::cin >> val) {
      if (val > curr_val) {
        std::cout << "The number following is " << val
                  << " and it is bigger than "<< curr_val << std::endl;
      } else {
        std::cout << "Number " << val << " is smaller than its precedor "
                  << curr_val
                  << " Make sure the next number is bigger than " << val
                  << std::endl;
        curr_val = val;
      }
      // update curr_val for the next loop
      curr_val = val;
    }
  }
  return 0;
}
