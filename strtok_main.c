#include "main.h"

/**
 * 
*/

int main()
{
    char *ptr = "Hello yadi!";
    char *delim = " ";
    char **arr_word;
    int i;

    *arr_word = _strtok(ptr, delim);
    
    i = 0;
    while ((arr_word + i) != NULL)
    {
        printf("Word[i] = %s\n", arr_word[i]);
        i++;
    }

    return (0);
}