#include <iostream>
#include "Sales_item.h"

int main()
{
  std::cout << "Enter the ISBN of the item "
            << std::endl;

  std::cout << "ISBN, number of copies sold sales, price." << std::endl;
  std::cout << "Press Enter to start inputing a new item." << std::endl;

  Sales_item my_item;

  while(std::cin >> my_item) {
    std::cout << my_item
  }

  std::cout << "See you next time!" << std::endl;
  return 0;
}
