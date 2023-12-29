#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 **/

int main()
  {
    char *path = getenv("PATH");

    char *token = strtok(path, ":");
    if (token == NULL)
      return (-1);
    
    while (token != NULL)
      {
	printf("%s\n", token);
	token = strtok(NULL, ":");
      }
  }
