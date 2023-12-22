#include <stdio.h>
#include <unistd.h>

/**
 *
 */

int main(void)
  {
    int pid = fork();

    if (pid < 0)
      perror("Error fail fork");
    else if (pid == 0)
      {
	int pid_child = fork();

	if (pid_child == 0)
	  printf("pid_child--child: %d\n", getpid());
	else if (pid_child > 0)
	  printf("pid_child--parent_but_child_of_pid: %d\n", getpid());
      }
    else
      {
	printf("parent pid: %d\n", getpid());
      }

    return (0);
  }
