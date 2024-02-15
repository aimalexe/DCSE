// 1: Write a program for parallel file copying using multiple processes. (First check if the no of files entered are even and if yes then create a child process for each pair and read from one and write to other) ./task.o f1.txt f2.txt f3.txt ...

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

    pid_t processId;
    for (int i = 1; i < argc; i += 2)
    {
        if ((processId = fork()) < 0)
        {
            perror("Process Creation Failed!!\n");
            return 1;
        }
        else if (processId == 0)
        {
            if (readWrite(argv[i], argv[i + 1]) < 0)
            {
                perror("Something went wrong while reading or writing a file.\n");
                return 1;
            }
            printf("Copied from SRC: %s to DIST: %s.\n", argv[i], argv[i + 1]);
            return 0;
        }
        else
            wait(NULL);
    }
    printf("Task completed.\n");
    return 0;
}