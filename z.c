#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;
    char *arg[] = {"ls", NULL};

    if (setenv("FILE_", arg[i], 1) != 0) {
        perror("setenv failed!");
        return -1;
    }

    return 0;
}
