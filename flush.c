#include <stdio.h>

/**
 *
 **/

int main()
  {
    char *str;
    FILE *fp = fopen("path_file", "w+");
    if (fp == NULL)
      return (-1);

    
    
    printf("trying the fflush fanctionality\n");
    scanf("%s", str);
    fflush(fp);
    
    return (0);
  }
