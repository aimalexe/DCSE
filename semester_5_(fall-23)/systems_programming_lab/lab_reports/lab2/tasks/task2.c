/*
Task 2: Analyze the return values and error numbers/error stings of wait system call on:
Success, Failure
Using: Strerror, Perror
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int childProcessId = fork();
    printf("Child Process Id: %d\n", childProcessId);

    if (childProcessId == 0)
    {
        printf("We are in child process.\n");
        int error = wait(NULL);
        if (error == -1)
        {

            printf("Has Error? Yes\n");
            printf("Error number: %d\n", errno);
            printf("Error: %s\n", strerror(errno));
        }
        else
        {
            printf("Has Error? No\n");
            printf("Error number: %d\n", errno);
            printf("Error: %s\n", strerror(errno));
        }
    }
    else
    {
        printf("We are in parent process.\n");
        int error = wait(NULL);
        if (error != -1)
        {
            printf("Has Error? No\n");
            printf("Error number: %d\n", errno);
            printf("Error: %s\n", strerror(errno));
        }
        else
        {
            printf("Has Error? Yes\n");
            printf("Error number: %d\n", errno);
            printf("Error: %s\n", strerror(errno));
        }
    }

    return 0;
}