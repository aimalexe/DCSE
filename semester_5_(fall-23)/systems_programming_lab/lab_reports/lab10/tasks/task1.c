// A program in which a child writes a string to a pipe and the parent reads the string.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define MAX_BUFF_SIZE 128

int main()
{
    int fd[2];
        if (pipe(fd) == -1)
    {
        perror("Error While creating pipe.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Error while creating childs.\n");
        return 1;
    }
    if(pid == 0){
        char *str = "Hello Baba\n";
        if(write(fd[1], str, strlen(str) + 1) == -1){
            perror("Error while writing to pipe.\n");
            return 1;
        }
    }

    else{
        char buff[MAX_BUFF_SIZE];
        if(read(fd[0], buff, MAX_BUFF_SIZE) == -1){
            perror("Error while reading from pipe.\n");
            return 1;
        }
        printf("Parent received: %s", buff);
    }

    return 0;
}