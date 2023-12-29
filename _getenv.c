#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 **/

char *_getenv(const char *name)
  {
    extern char **environ;
    int i = 0;
    char *env_name;
    int max;
    char *temp_env;

    while (environ[i] != NULL)
      {
	max = 0;
	while (environ[i][max] != '\0')
	  max++;
	
	temp_env = malloc(++max * sizeof(char));
	if (temp_env == NULL)
	  {
	    perror("malloc fail!!!");
	    return (NULL);
	  }
	strcpy(temp_env, environ[i]);
	
	env_name = strtok(temp_env, "=");

	if (!strcmp(env_name, name))
	  {
	    max = 0;
	    while (env_name[max] != '\0')
	      max++;

	    return ((temp_env + ++max));
	  }
	else
	  i++;
      }
    
  }


int main()
  {
    char *value = _getenv("PATH");
    
    printf("%s\n", value);

    return (0);
  }
