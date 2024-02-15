// Write a program “minmax.c” that takes an array as command line arguments. Program executes min.c and max.c programs in its two child processes. One child process calculates and returns the min value and other calculates and returns the max value in the array. The program “minmax.c” shall receive the values returned by the child processes and display these values

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s number1 [number2 ...]\n", argv[0]);
        return 1;
    }

    printf("Parent Id: %d\n", getpid());
    printf("The parent file name is: %s\n", argv[0]);

    int status, childProcess;

    for (int i = 0; i < 2; i++)
    {
        if ((childProcess = fork()) < 0)
        {
            perror("Forking failed!\n");
            return -1;
        }
        else if (childProcess == 0 && i == 0)
            execvp("./task3a.o", argv);
        else if (childProcess == 0 && i == 1)
            execvp("./task3b.o", argv);

        if (childProcess > 0)
        {
            wait(&status);

            if (WIFEXITED(status) && i == 0)
                printf("Min Value = %d\n", WEXITSTATUS(status));

            if (WIFEXITED(status) && i == 1)
                printf("Max Value = %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
