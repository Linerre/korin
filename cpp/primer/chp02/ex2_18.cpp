#include <iostream>

int main()
{
  int num_one = 321;
  int num_two = 822;

  int *ptr_one = &num_one;
  int *ptr_two = &num_two;

  std::cout << "The original address of Pointer One is "
            << ptr_one << std::endl;
  std::cout << "The original value Pointer One points to is "
            << num_one << std::endl;

  std::cout << "The original address of Pointer Two is "
            << ptr_two << std::endl;
  std::cout << "The original value Pointer Two points to is "
            << num_two << std::endl;

  // change the val of a ptr means to change the address it points
  // pointer one now points to num_two
  ptr_one = &num_two;
  std::cout << "Now the address of Pointer One becomes "
            << ptr_one << std::endl;

  // change the value to which the pointer points
  *ptr_two = 823;
  std::cout << "Now the val that Pointer Two points to becomes "
            << num_two << std::endl; // 823

  return 0;
}
