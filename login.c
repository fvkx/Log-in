#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char enter_Password[50];
    const char *password = "kauhgdiuaw";

    while (true) {
        printf("Enter password: ");

        // limit input to avoid buffer overflow
        scanf("%49s", enter_Password);

        if (strcmp(enter_Password, password) == 0) {
            printf("Correct password\n");
            break; // exit loop when correct
        } else {
            printf("Incorrect password\n");
        }
    }

    return 0;
}

