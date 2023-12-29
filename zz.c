#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void find_files(const char *filename) {
    char *path_env = getenv("PATH");
    char *path = strtok(path_env, ":");
    int found = 0;

    while (path != NULL) {
        char file_path[256];
        sprintf(file_path, "%s/%s", path, filename);

        if (access(file_path, F_OK) == 0) {
            printf("%s\n", file_path);
            found = 1;
        }

        path = strtok(NULL, ":");
    }

    if (!found) {
        printf("%s not found in the current PATH.\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        find_files(argv[i]);
    }

    return 0;
}
