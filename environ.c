#include <stdio.h>
#include <stdlib.h>

/**
 *
 **/

int main(void)
  {
    extern char **environ;
    int i = 0;
    
    while (environ[i] != NULL)
      {
	printf("%s\n", environ[i]);
	printf("\n------------------------------------------------\n");
	i++;
      }

    return (0);
  }
