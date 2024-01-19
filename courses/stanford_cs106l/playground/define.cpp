#include <iostream>

#define MAX(x, y) ((x) > (y) ? x : y)


int main() {
  int ret = MAX(9, 10);
  std::cout << "MAX 9 and 10: " << ret << std::endl;
  return 0;
}
