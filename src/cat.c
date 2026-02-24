#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 512

int main() {
    char buffer[BUFFER_SIZE];
    read(STDIN_FILENO, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    return 0;
}