#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    
    FILE *file = stdin;
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
    }

    int bytes_read;
    while (1) {
        // Reading the input stream
        bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        if (bytes_read < 0) {
            perror("Error reading input stream");
            return 1;
        }
        if (bytes_read > 0) {
            // Actually print the output!
            write(STDOUT_FILENO, buffer, bytes_read);
        } else {
            break; // EOF reached
        }
    }

    fclose(file);
    return 0;
}