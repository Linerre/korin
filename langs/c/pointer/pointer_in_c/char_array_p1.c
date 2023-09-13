#include <stdio.h>
#include <string.h>

int main()
{
  /**
   Two ways to define a character array:
   1. Use brackets, with the length declared either implicitly or explicitly;
      - Length should be >= the num of array chars + 1
      - No need to put a NULL character explicitly at the end of the string.
      - To get the real len of the string, use strlen from string.h.

   2. Use curly braces and must explicitly include the \0 character.
      - The array defination must include the NULL character
  */

  /* G[] also works, but the char array must be initialized. */
  char G[7] = "Hello!";         /* G[6] works, but older cc may fail it */

  /* Must include `\0' in the array defination */
  char H[] = {'H', 'i', '!', '\0'};
  printf("%s\n", H);
  return 0;
}
