#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[], char *envp[])
{
  char *home, *host;

  home = getenv("HOME");
  host = getenv("HOSTNAME");
  if (host == NULL) {
    char *unknown = "Unknown";
    host = unknown;
  }

  printf("Your home directory is %s on %s.\n", home, host);

  return 0;
}
