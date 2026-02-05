#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "python_embed.h"

#define MAX_PASSWORD_LEN 50

int main(void) {
    python_init();
    python_run_banner();

    char enter_Password[MAX_PASSWORD_LEN];
    const char *password = "kauhgdiuaw";

    while (true) {
        printf("Enter password: ");

        // check scanf return value to avoid warning
        if (scanf("%49s", enter_Password) != 1) {
            printf("Input error\n");
            break;
        }

        if (strcmp(enter_Password, password) == 0) {
            printf("Correct password\n");
            break;
        } else {
            printf("Incorrect password\n");
        }
    }

    python_shutdown();
    return 0;
}

