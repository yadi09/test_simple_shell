#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 */

int main(void)
{
  int pid = fork();
  int n, i;

  if (pid == 0)
    {
      n = 1;
    }
  else
    {
    n = 6;
    wait(NULL);
    }
  for (i = 0; i < 5; i++)
    {
      printf("%d ", n + i);
      fflush(stdout);
    }

  printf("\n");
  
  return (0);
}
