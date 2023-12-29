#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

/**
 *
 **/

int main(int argc, char **argv)
{
  int i;
  struct stat st;
  
  if (argc < 2)
    {
      printf("Usage: %s path_to_file .......\n", argv[0]);
      return (0);
    }

  i = 1;
  while (i < argc)
    {
      printf("%s: ", argv[i]);
      if (stat(argv[i], &st) == 0)
	{
	  printf("FOUND\n");
	  printf("%u %u %s\n", st.st_mode, st.st_uid, ctime(&st.st_atime));
	}
      else
	{
	  printf("NOT FOUND\n");
	}
      i++;
    }

  return (0);
}
