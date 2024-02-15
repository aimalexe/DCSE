// Implement “Cat” utility

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
    int readWriteReturnValue, keyboard = STDIN_FILENO, screen = STDOUT_FILENO, file;
    if (argc == 1)
    {
        // for 'cat' read from stdin and print on stdout.
        readWriteReturnValue = readWriteOnly(&keyboard, &screen);
        if (readWriteReturnValue < 0)
        {
            perror("Something went wrong while reading from stdin or writing to stdout.\n");
            return 1;
        }
    }
    else if (argc == 2)
    { // for 'cat file' read from file and write to stdout.
        file = open(argv[1], O_RDONLY);
        if (file == -1)
        {
            fprintf(stderr, "Something went wrong while opening the source file: %s due to %s\n", argv[1], strerror(errno));
            return -1;
        }

        readWriteReturnValue = readWriteOnly(&file, &screen);
        if (readWriteReturnValue < 0)
        {
            perror("Something went wrong while reading from stdin or writing to stdout.\n");
            return 1;
        }

        if (close(file) == -1)
        {
            fprintf(stderr, "Error while closing the file. %s\n", strerror(errno));
            return 1;
        }
    }
    else if (argc == 3)
    { // for 'cat > file' read from stdin and write to file.
        file = open(argv[3], O_CREAT | O_TRUNC, S_IRWXG | S_IRWXO | S_IRWXU);
        if (file == -1)
        {
            fprintf(stderr, "Something went wrong while opening the source file: %s due to %s\n", argv[1], strerror(errno));
            return -1;
        }

        readWriteReturnValue = readWriteOnly(&keyboard, &file);
        if (readWriteReturnValue < 0)
        {
            perror("Something went wrong while reading from stdin or writing to stdout.\n");
            return 1;
        }

        if (close(file) == -1)
        {
            fprintf(stderr, "Error while closing the file. %s\n", strerror(errno));
            return 1;
        }
    }
    else if (argc == 4)
    { // for 'cat file1 > file2' read from file1 and write to file2.
        readWriteReturnValue = readWrite(argv[2], argv[4]);
        if (readWriteReturnValue < 0)
        {
            perror("Something went wrong while reading from stdin or writing to stdout.\n");
            return 1;
        }
    }

    return 0;
}