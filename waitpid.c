#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
  {
    int pid1 = fork();
    if (pid1 < 0)
      {
	perror("pid1 fork fail\n");
	return (-1);
      }
    else if (pid1 == 0)
      {
	sleep(4);
	printf("child pid1\n");
	exit(90);
      }

    int pid2 = fork();
    if (pid2 < 0)
      {
        perror("pid2 fork fail\n");
	return (-1);
      }
    else if (pid2 == 0)
       {
        printf("child pid2\n");
        exit(80);
      }

    waitpid(-1, NULL, 0);
    printf("paretnt pid\n");
  }
