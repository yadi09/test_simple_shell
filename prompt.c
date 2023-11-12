#include <stdio.h>
#
/**
 * 
*/

int main()
{
    char *ptr = NULL;
    int n = 0;
    ssize_t max_read;

    printf("$ ");
    max_read = getline(&ptr, &n, stdin);
    printf("%s", ptr);

    return (max_read);
}