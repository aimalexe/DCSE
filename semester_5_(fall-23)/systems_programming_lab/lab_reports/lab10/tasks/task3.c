#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <FIFO_NAME>\n", argv[0]);
        return 1;
    }

    const char *fifoName = argv[1];
    char buf[1024];
    ssize_t numBytes;

    // Create a FIFO if it does not exist
    if (mkfifo(fifoName, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    // Fork a process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process for writing to FIFO
        int fifoFd = open(fifoName, O_WRONLY);
        if (fifoFd == -1) {
            perror("open");
            return 1;
        }

        while (fgets(buf, sizeof(buf), stdin)) {
            write(fifoFd, buf, sizeof(buf));
        }

        close(fifoFd);
    } else { // Parent process for reading from FIFO
        int fifoFd = open(fifoName, O_RDONLY);
        if (fifoFd == -1) {
            perror("open");
            return 1;
        }

        while ((numBytes = read(fifoFd, buf, sizeof(buf))) > 0) {
            write(STDOUT_FILENO, buf, numBytes);
        }

        close(fifoFd);
    }

    return 0;
}
