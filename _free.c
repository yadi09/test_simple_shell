#include "main.h"
#include <stdlib.h>

/**
 *
 */

void _free(char **ptr)
  {
    int i = 0;
    
    while(ptr[i] != NULL)
      {
	free(ptr[i]);
	i++;
      }

    free(ptr);
  }
