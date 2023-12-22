#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char* _strtok(char* str, const char* delim);
int count_words(char *str, char *delim);
void _free(char **ptr);

#endif
