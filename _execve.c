#include <stdio.h>
#include <unistd.h>

/**
 *
 */

int main(void)
{
  char *path = "/usr/bin/ls";
  char *argv[] = {"ls", "-l", NULL};;
  int _return;
  
  printf("Before execve()\n");

  _return = execve(path, argv, NULL);
  if (_return == -1)
    perror("fail execve()");

  printf("\nafter execve()\n");

  return (0);
}
