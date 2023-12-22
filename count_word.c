#include <string.h>
#include "main.h"

/**
 *
 */

int count_words(char *str, char *delim)
{
  int i, j, count = 1;
  
  if (str == NULL || delim == NULL)
    return ('\0');

  for (i = 0; delim[i] != '\0'; i++)
    {
      for (j = 0; str[j] != '\0'; j++)
	{
	  if (str[j] == delim[i])
	    {
	      i++;
	      if (delim[i] == '\0' && str[j + 1] != '\0')
		{
		  count++;
		  i = 0;
		}
	    }
	  else
	    {
	      i = 0;
	    }
	}
      break;
    }

  return (count);
}
