#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int bytes_read = 1;
    while (1) {
        bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Error reading input stream");
            return 1;
        }
        if (bytes_read > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        } else {
            break; // EOF reached
        }
    }
    return 0;
}