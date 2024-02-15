// Task 3: Write a program that monitors N files using 'select'.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
#include "../../reusable_code_snippets/findMax.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s FILE_1 [FILE_N...]\n", argv[0]);
        return 1;
    }

    int length = argc - 1;
    int fds[length];

    for (int i = 0; i < length; i++)
    {
        fds[i] = open(argv[i + 1], O_RDWR);
        if (fds[i] == -1)
        {
            fprintf(stderr, "Something went wrong while opening the file: %s due to %s\n", argv[i + 1], strerror(errno));
            return 1;
        }
    }

    fd_set readSet;
    FD_ZERO(&readSet);

    int max = findMax(fds, &length);

    for (int i = 0; i < length; i++)
        FD_SET(fds[i], &readSet);

    int ret = select(max + 1, &readSet, NULL, NULL, NULL);

    for (int i = 0; i < length; i++)
        if (FD_ISSET(fds[i], &readSet))
            printf("The file: %s with FD = %d is ready.\n", argv[i + 1], fds[i]);

    for (int i = 0; i < length; i++)
        if (close(fds[i]) == -1)
        {
            fprintf(stderr, "Something went wrong while closing the file: %s due to %s\n", argv[i + 1], strerror(errno));
            return 1;
        }

    return 0;
}
