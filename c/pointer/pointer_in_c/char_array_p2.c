#include <stdio.h>

int main()
{
  /**
     character array object is itself a pointer to its 1st element.
     Thus the var bound to it can be used to access other elements:
     Arr[i] == *(Arr + i)
  */
  char G[7] = "Hello!";
  if(G[4] == *(G+4))
      printf("%c\n", G[4]);

  /* Note this is invalid */
  char *g = &G;

  /* This is valid however */
  char *g;
  g = G;

  printf("Traverse the array using a pointer:\n");
  while(*g != '\0')
  {
    printf("The char is: %c\n", *g);
    g++;
  }
  return 0;
}
