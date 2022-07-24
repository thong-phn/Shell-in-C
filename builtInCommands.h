#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int numberOfBuiltIns();
int builtInCD(char **args);
int builtInHELP(char **args);
int builtInEXIT(char **args);