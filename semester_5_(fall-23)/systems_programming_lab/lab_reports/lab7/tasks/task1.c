// Task 1: Write a program that copies two files sequentially in a single process

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../reusable_code_snippets/readWrite.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s FILE_1 FILE_2 [FILE_N...]\n", argv[0]);
        return 1;
    }

    if (argc % 2 == 0)
    {
        perror("Argument must be even in count.\n");
        return 1;
    }

    // int readWriteReturnValue;
    for (int i = 1, readWriteReturnValue; i < argc; i += 2)
    {
        readWriteReturnValue = readWrite(argv[i], argv[i + 1]);
        if (readWriteReturnValue < 0)
        {
            perror("Something went wrong while reading or writing a file.\n");
            return 1;
        }
        printf("Copied from SRC: %s to DIST: %s.\n", argv[i], argv[i + 1]);
    }

    printf("Sequential copy completed.\n");

    return 0;
}