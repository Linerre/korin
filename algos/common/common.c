/*
  Implementations for common procedures called by all other ADTs and
  algorithms implemented in C.
 */

#include <stdio.h>
#include <stdlib.h>

void Error(char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}
