// Write a program that creates a process fan. Parent process writes to the pipe and all the child processes read the message from pipe and display it on stdout.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_BUFF_SIZE 128
#define CHILD_COUNT 3

int main()
{
    int fd[2], i;
    pid_t pid;
    char *str = "Hello Baba\n", buff[MAX_BUFF_SIZE];
    if (pipe(fd) == -1)
    {
        perror("Error While creating pipe.\n");
        return 1;
    }
    
    for (i = 0; i < CHILD_COUNT; i++)
    {
        if ((pid = fork()) == -1)
        {
            perror("Error while creating childs.\n");
            return 1;
        }

        if (pid == 0)
        {
            if (read(fd[0], buff, MAX_BUFF_SIZE) == -1)
            {
                perror("Error while reading from pipe.\n");
                return 1;
            }
            printf("Child [%ld] received: %s", (long)(getpid()), buff);
            break;
        }
        else
        {
            wait(NULL);
            if (write(fd[1], str, strlen(str) + 1) == -1)
            {
                perror("Error while writing to pipe.\n");
                return 1;
            }
        }
    }

    return 0;
}