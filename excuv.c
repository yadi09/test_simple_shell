#include <unistd.h>
#include <stdio.h>

/**
 *
 **/

int main()
  {
    char *args[] = {"/bin/echo", "hello world", NULL};

    execve(args[0], args, NULL);
    printf("Error\n");
    return (0);
  }
