#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    read = getline(&line, &len, stdin);

    if (read != -1)
    {
        printf("%s\n", line);
    }

    free(line);

    return (0);
}