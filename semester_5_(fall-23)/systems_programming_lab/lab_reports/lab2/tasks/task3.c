/*
Task 3: Analyze the return values and error numbers/error stings of close system call on:
Success, Failure
Using:  Strerror, Perror
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fileDescriptor;

    printf("Enter a number to close that file? ");
    scanf("%d", &fileDescriptor);

    int hasError = close(fileDescriptor);
    if (hasError == 0)
    {
        printf("Has Error? No\n");
        printf("Error number: %d\n", errno);
        printf("Error: %s\n", strerror(errno));
        printf("File closed successfully :)");
    }
    else
    {
        printf("Has Error? Yes\n");
        printf("Error number: %d\n", errno);
        printf("Error: %s\n", strerror(errno));
        perror("This file is not opened. How can i close it??\n");
    }
    return 0;
}