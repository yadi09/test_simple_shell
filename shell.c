#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 **/

int main(void)
{
  char *argv[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
  char *envp[] = {NULL};
  int i, status;
  pid_t pid;

  for (i = 0; i < 5; i++)
    {
      pid = fork();
      if (pid < 0)
	{
	  perror("fork gets error!!!\n");
	  return (-1);
	}
      else if (pid == 0)
	{
	  printf("The parent PID: %d\n", getppid());
	  if (execve(argv[0], argv, envp) == -1)
	    {
	      perror("execve gets error!!!");
	      return (-1);
	    }
	}
      else
	wait(&status);
    }

  return (-1);
}
