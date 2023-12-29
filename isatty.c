#include <stdio.h>
#include <unistd.h>

/**
 *
 **/

int main()
  {
    if (isatty(STDOUT_FILENO) == 1)
      printf("This is Terminal\n");
    else if (isatty(STDOUT_FILENO) == 0)
      printf("Not terminal\n");
    else
      printf("error\n");

    return (0);
  }
