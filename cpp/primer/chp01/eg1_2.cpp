#include <iostream>
int main()
{
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;

  // NOTE: cin first takes whatever valid stream (not whitespace or EOL)
  // is passed and puts it into v1; then it returns itself again
  // The returned cin does the same to the next valid stream
  std::cin >> v1 >> v2;
  std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 + v2 << std::endl;
  return 0;
}
