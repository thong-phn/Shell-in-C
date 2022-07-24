#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 64
#define TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * @brief Reading a line
 * 
 * @return char* 
 */
char *readLine(void) {
    int bufferSize = BUFFER_SIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufferSize);
    int c;

    if (!buffer) {
        printf("readLine: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Read a character
        c = getchar();

        // If we hit EOF, replace with a NULL and return
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we exceeded the buffer, reallocate memory
        if (position >= bufferSize) {
            bufferSize += BUFFER_SIZE;
            buffer = realloc(buffer, bufferSize);
            if (!buffer) {
                printf("readLine: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
 * @brief Spliting a line into args
 * 
 * @param line 
 * @return char** List of args (tokens)
 */
char **splitLine(char *line) {
    int bufferSize = TOK_BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(buferSize * sizeof(char*));
    if (!tokens) {
        printf("splitLine: allocation error\n");
        exit(EXIT_FAILURE);
    }

    // get the first token
    char *token = strtok(line, TOK_DELIM);
    // copy every token to a list 
    while (token != NULL) {
        tokens[position] = token;
        position++;

        // allocation if lack of memory
        if (position >= bufferSize) {
            bufferSize += TOK_BUFFER_SIZE;
            tokens = realloc(tokens, bufferSize * sizeof(char*));
            if (!tokens) {
                printf("splitLine: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        // walk through other tokens
        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int launch(char **args) {

}
void myLoop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = readLine();
        args = splitLine();
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv) {
    // Load config file
    // Run command loop
    myLoop();
    // Clean up and shutdown
    return EXIT_SUCCESS;
}