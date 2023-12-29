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
  char *envp[] = {"FILE_=ls", NULL};
  int i, pid;
  char *buffer = NULL;
  FILE *fp = fopen("./path_file", "r");
  
  if (fp == NULL)
    {
      perror("fp fails!!!");
      return (-1);
    }

  argv[argc] = NULL;
  

  if (argc < 2)
    return (0);

  i = 1;
  while (argv[i])
    {
      printf("1\n");
      pid = fork();
      if (pid < 0)
	{
	  perror("fork fail!!!");
	  return (-1);
	}
      else if (pid == 0)
	{
	  printf("c2\n");
	  if (execve("./_which.sh", argv, envp) == -1)
	    {
	      perror("execve fails!!!");
	      return (-1);
	    }
	}
      else
	{
	  wait(NULL);
	  if (!(getline(&buffer, NULL, fp)))
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
