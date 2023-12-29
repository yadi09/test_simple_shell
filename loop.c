#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/**
 *
 **/

void stop()
  {
    return;
  }
int main()
  {
    signal(SIGINT, stop);
    signal(SIGTERM, stop);
    
    while (1)
      {
	printf("you can't stop me!!! PID: %d\n", getpid());
	sleep(1);
      }
  }
