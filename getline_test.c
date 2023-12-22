#include <stdio.h>
#include "main.h"

/**
 *
 */

int main()
{
  char *buf = NULL;
  size_t length = 0;

  printf("$ ");
  my_getline(&buf, &length, stdin);

  printf("%s", buf);

  return (0);
}
