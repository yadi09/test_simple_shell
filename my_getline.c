#include "main.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t line_max;

        if (*lineptr == NULL)
        {
        *n = 5;
        *lineptr = malloc(sizeof(char) * (*n));

        if (*lineptr == NULL)
        {
        printf("UNABLE to allocat memory fpr lineptr!!!");
        return (-1);
        }
        }

        line_max = 0;

        while (1)
        {
        int c;

        c = fgetc(stream);
        if (c == EOF)
        {
        if (line_max == 0)
        return (-1);
        else
        {
        *lineptr[line_max] = '\0';
        return (line_max);
        }
        }

        *lineptr[line_max] = c;
        line_max++;

        if (line_max >= (ssize_t)*n)
        {
        *n = *n + 2;
        *lineptr = realloc(*lineptr, *n);
        if (*lineptr == NULL)
        {
        printf("UNABLE to realloc for re_buffer!!!");
        return (-1);
        }
        }
        

        }