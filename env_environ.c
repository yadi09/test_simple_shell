#include <stdio.h>
#include <stdlib.h>

/**
 *
 **/

int main(int argc, char *argv[], char **env)
  {
    extern char **environ;
    
    printf("env_address: %p -------- environ_address: %p\n", env, environ);

    return (0);
  }
