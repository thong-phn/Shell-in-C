#include <unistd.h>
#include "builtInCommands.h"

/** define variables **/
char *builtInString[] = {
    "cd",
    "help",
    "exit"
};

int (*builtInFunction[]) (char **) = { // function pointer
    &builtInCD,
    &builtInHELP,
    &builtInEXIT,
};

int numberOfBuiltIns() {
    return sizeof(builtInString)/sizeof(char *);
}

/** built-in commands **/
int builtInCD(char **args) {
    if (args[1] == NULL) {
        printf("cd: expected argument to \" cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("Error: ");
        }
    }
    return 1;
}

int builtInHELP(char **args) {
    printf("Thong P. Shell\n");
    printf("This is CS50\n");
    printf("The following commands are built in:\n");

    for (int i = 0; i < numberOfBuiltIns(); i++) {
        printf(" %s\n", builtInString[i]);
    }

    return 1;
}

int builtInEXIT(char **args) {
    return 0;
}