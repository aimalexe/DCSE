// Implement the cp command.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "../../reusable_code_snippets/readWrite.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s SOURCE DESTINATION.\n", argv[0]);
        return 1;
    }

    // 1. open sourc file (for reading only)
    int srcFile = open(argv[1], O_RDONLY);
    if (srcFile == -1)
    {
        fprintf(stderr, "Something went wrong while opening the source file: %s due to %s\n", argv[1], strerror(errno));
        return 1;
    }

    // 2. open destination file if not present create it (for writing only)
    int destFile = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO);
    if (destFile == -1)
    {
        fprintf(stderr, "Something went wrong while opening the destination file: %s due to %s\n", argv[2], strerror(errno));
        return 1;
    }

    // 3. Read from src file
    // 4. write to destination from src file
    if (readWriteOnly(&srcFile, &destFile) < 0)
    {
        perror("Something went wrong while reading or writing a file.\n");
        return 1;
    }

    // 5. Close destination and src files
    int closeSrc = close(srcFile);
    int closeDest = close(destFile);
    if (closeSrc == -1 || closeDest == -1)
    {
        fprintf(stderr, "Error while closing the file. %s\n", strerror(errno));
        return 1;
    }

    printf("Coping Successful :)\n");

    return 0;
}