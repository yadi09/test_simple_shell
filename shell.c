#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *
 **/

int main(void)
{
  char *argv[] = {NULL, NULL};
  char *envp[] = {NULL};
  char *buffer = NULL;
  size_t size = 0;
  int pid, status;

  while (1)
    {
      printf("#cisfun$ ");
      getline(&buffer, &size, stdin);
      buffer[strlen(buffer) - 1] = '\0';

      pid = fork();

      if (pid < 0)
	{
	  perror("fork gets error!!!\n");
	  return (-1);
	}
      else if (pid == 0)
	{
	  argv[0] = malloc((strlen(buffer) + 1) * sizeof(char));
	  if (argv[0] == NULL)
	    return (-1);

	  strcpy(argv[0], buffer);
	  
	  if (execve(buffer, argv, envp) == -1)
	    {
	      perror("execve gets error!!!\n");
	      free(buffer);
	      free(argv[0]);
	      return (-1);
	    }
	}
      else
	{
	  wait(&status);
	}
    }

  return (0);
}
