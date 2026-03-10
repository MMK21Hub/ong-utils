#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void print_file(FILE *file) {
    char buffer[BUFFER_SIZE];

    int bytes_read;
    while (1) {
        // Reading the input stream
        bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        if (bytes_read < 0) {
            perror("Error reading input stream");
            exit(1);
        }
        if (bytes_read > 0) {
            // Actually print the output!
            write(STDOUT_FILENO, buffer, bytes_read);
        } else {
            break; // EOF reached
        }
    }
}

void open_and_print_file(char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        // TODO include filename in error msg
        perror("Error opening file");
        exit(1);
    }
    print_file(file);
    fclose(file);
}

int main(int argc, char *argv[]) {    
    if (argc < 2) {
        // No args provided, so print stdin
        print_file(stdin);
        return 0;
    }

    // Concatenate the provided file paths
    for (int i = 1; i < argc; i++) {
        open_and_print_file(argv[i]);
    }
    return 0;
}