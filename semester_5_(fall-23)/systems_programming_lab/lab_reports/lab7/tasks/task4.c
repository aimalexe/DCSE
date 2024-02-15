/*
Task 4: Write a program that creates two child processes, both child read from the
same source and writes to two separate destination, make sure you use select to
monitor if the source is ready to be read from.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#include "../../reusable_code_snippets/readWrite.h"
#include "../../reusable_code_snippets/findMax.h"

int main(int argc, char *argv[])
{
    if (argc <= 3)
    {
        fprintf(stderr, "Usage:\n%s READ_FROM_FILE_1 WRITE_TO_FILE_1 WRITE_TO_FILE_2 [WRITE_TO_FILE_N...]\n", argv[0]);
        return 1;
    }

    int readFd = open(argv[1], O_RDONLY);
    if (readFd == -1)
    {
        fprintf(stderr, "Cannot open source file %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    for (int i = 2; i < argc; i++)
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("Failed to create child process.\n");
            return 1;
        }
        else if (pid == 0)
        { // Child
            int writeFd = open(argv[i], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
            if (writeFd == -1)
            {
                fprintf(stderr, "Cannot open destination file %s: %s\n", argv[i], strerror(errno));
                return 1;
            }

            fd_set readSet;
            FD_ZERO(&readSet);
            FD_SET(readFd, &readSet);

            // Child process has to select on the readFd again because file descriptors are shared.
            if (select(readFd + 1, &readSet, NULL, NULL, NULL) > 0)
            {
                if (FD_ISSET(readFd, &readSet))
                    if (readWriteOnly(&readFd, &writeFd) == -1)
                    {
                        fprintf(stderr, "Error reading/writing files.\n");
                        return 1;
                    }
            }
            else
            {
                perror("Error while monitoring files.\n");
                return 1;
            }

            if (close(writeFd) == -1)
            {
                fprintf(stderr, "Something went wrong while closing the file: %s due to %s\n", argv[i], strerror(errno));
                return 1;
            }
            printf("Process -> %d, %d.\n", i, writeFd);
            return 0; // Child process exits after writing.
        }
    }

    // Parent process
    for (int i = 2; i < argc; i++)
        wait(NULL); // Wait for all children to finish.

    // Close the source file descriptor in the parent as well.
    if (close(readFd) == -1)
    {
        fprintf(stderr, "Something went wrong while closing the file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    };

    printf("Reading from file: %s and writing to other files completed.\n", argv[1]);
    return 0;
}