// Task 2: Write a program that monitors two files using 'select'.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include "../../reusable_code_snippets/readWrite.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s FILE_1 FILE_2\n", argv[0]);
        return 1;
    }

    // 1. Opening the two files.
    int file1 = open(argv[1], O_RDWR);
    if (file1 == -1)
    {
        fprintf(stderr, "Something went wrong while opening the file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    }

    int file2 = open(argv[2], O_RDWR);
    if (file2 == -1)
    {
        fprintf(stderr, "Something went wrong while opening the file: %s due to %s\n", argv[2], strerror(errno));
        return 1;
    }

    // 2. Collecting arguments for select function.
    int maxFd = file1 >= file2 ? file1 : file2;
    fd_set readset;
    FD_ZERO(&readset);

    FD_SET(file1, &readset);
    FD_SET(file2, &readset);

    // calling the function select.
    int readyFile = select(maxFd + 1, &readset, NULL, NULL, NULL);

    // Checking for ready file(S):
    if (FD_ISSET(file1, &readset))
        printf("The file: %s with FD = %d is ready.\n", argv[1], file1);

    if (FD_ISSET(file2, &readset))
        printf("The file: %s with FD = %d is ready.\n", argv[2], file2);

    // Closing the files:
    if (close(file1) == -1)
    {
        fprintf(stderr, "Something went wrong while closing the file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    }

    if (close(file2) == -1)
    {
        fprintf(stderr, "Something went wrong while closing the file: %s due to %s\n", argv[2], strerror(errno));
        return 1;
    }

    return 0;
}