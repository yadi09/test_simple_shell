#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 */

int main(void)
{
  int status;
  pid_t child_pid;

  child_pid = fork();
  if (child_pid < 0)
    {
      perror("Error:");
      return (-1);
    }
  else if (child_pid == 0)
    {
      printf("Wait for me, wait for me\n");
      sleep(5);
    }
  else
    {
      wait(&status);
      printf("Oh, it's all better now\n");
    }

  return (0);
}
