#include <stdio.h>
#include <unistd.h>

int main() {
    char current_dir[100];

    // Get the current working directory
    getcwd(current_dir, sizeof(current_dir));
    printf("Current working directory: %s\n", current_dir);

    // Change to a different directory
    if (chdir("/home/yadi0988/simple_shell") == 0) {
      printf("Changed working directory to %s\n", getcwd(current_dir, sizeof(current_dir)) ? current_dir : "(nil)");
    } else {
        perror("chdir failed");  // Print error message using perror
    }

    // Get the updated working directory
    getcwd(current_dir, sizeof(current_dir));
    printf("New working directory: %s\n", current_dir);

    return 0;
}
