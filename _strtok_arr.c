#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *
 */

char **token(char *str, char *delim)
{
  char **array_words;
  char *temp, *token;
  int i = 0;

  temp = malloc(strlen(str) * sizeof(char));
  if (temp == NULL)
    return (NULL);

  strcpy(temp, str);

  array_words = malloc((count_words(str, delim) + 1) * sizeof(char *));
  if (array_words == NULL)
    return (NULL);

  token = strtok(temp, delim);

  while (token != NULL)
    {
      array_words[i] = malloc(strlen(token) * sizeof(char));
      if (array_words[i] == NULL)
	{
	  if (i == 0)
	    {
	      free(array_words);
	      return (NULL);
	    }
	  i--;
	  while (i >= 0)
	    {
	      free(array_words[i]);
	      i--;
	    }
	  free(array_words);
	  return (NULL);
	}

      strcpy(array_words[i], token);
      token = strtok(NULL, delim);
      i++;
    }
  array_words[i] = NULL;
  free(temp);
  
  return (array_words);
}



int main()
  {
    char **temp = token("HELLO YADAMZER WELLCOM TO NEW TECH WORLD!!!", " ");

    int i;
    for (i = 0; temp[i] != NULL; i++)
      {
	printf("%s\n", temp[i]);
      }

    _free(temp);
  }
