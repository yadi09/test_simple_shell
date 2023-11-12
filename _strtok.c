#include <stdio.h>

/**
 * _strtok - function that splits a string and
 * Returns an array of each word of the string.
 * @str: string
 * @delim: delimeter
 * Return: array of each word of the string.
*/

char* _strtok(char* str, const char* delim)
{
    int count, i;
    char *string;
    char *cpy_str, *cpy_str2;
    char **word_tok;

    if (str == NULL || delim == NULL)
    {
        return ('\0');
    }

    cpy_str = strdup(str);
    count = 0;

    string = strtok(cpy_str, delim);

    while (string != NULL)
    {
        count++;
        string = strtok(NULL, delim);
    }
    free(cpy_str);

    cpy_str2 = strdup(str);

    word_tok = malloc(sizeof(char*) * count);

    char *token = strtok(cpy_str2, delim);
    i = 0;

    while (i < count)
    {
        word_tok[i] = strdup(token);
        token = strtok(NULL, delim);
        i++;
    }

    return (word_tok);
}