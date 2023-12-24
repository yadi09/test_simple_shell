#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 **/

int main(int argc, char *argv[])
{
  char *envp0 = NULL;
  char **ag;
  char **envp = malloc(2 * sizeof(char *));
  int i, pid;
  char *buffer = NULL;
  FILE *fp = fopen("./path_file", "r");
  
  if (fp == NULL)
    {
      perror("fp fails!!!");
      return (-1);
    }
  envp = malloc(2 * sizeof(char*));
  if (envp == NULL)
    {
      perror("malloc fails!!!");
      return (-1);
    }
  envp[0] = (char *)malloc(20 * sizeof(char));

  strcpy(envp[0], "FILE_=NULL");
  

  if (argc < 2)
    return (0);

  i = 1;
  while (argv[i])
    {
      pid = fork();
      if (pid < 0)
	{
	  perror("fork fail!!!");
	  return (-1);
	}
      else if (pid == 0)
	{
	  if (!(setenv("FILE_", argv[i], 1)))
	    {
	      perror("setenv fails!!!");
	      return (-1);
	    }
	  if (execve("./_which.sh", argv, envp) == -1)
	    {
	      perror("execve fails!!!");
	      return (-1);
	    }
	}
      else
	{
	  wait(NULL);
	  if (!(getline(&buffer, 0, fp)))
	    {
	      perror("getline fails!!!");
	      return (-1);
	    }
	  printf("%s\n", buffer);
	  free(buffer);
	}
      i++;
    }

  return (0);
}
