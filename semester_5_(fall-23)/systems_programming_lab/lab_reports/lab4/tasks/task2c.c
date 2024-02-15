// Write a program that takes integers as arguments & adds & multiplies them using the above two programs.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if ((argc <= 1) || (argc > 4))
    {
        fprintf(stderr, "Usage: %s number1 [number2] [number3]\n", argv[0]);
        return 1;
    }

    printf("Parent Id: %d, and The file name is: %s\n", getpid(), argv[0]);

    for (int i = 0; i < 2; i++)
    {
        pid_t childProcess = fork();
        if (childProcess < 0)
        {
            printf("Forking failed!\n");
            return 1;
        }
        else if (childProcess == 0 && i == 0)
        {
            execlp("./task2a.o", "task2a.o", argv[1], argv[2], argv[3], NULL);
            exit(1);
        }
        else if (childProcess == 0 && i == 1)
        {
            execlp("./task2b.o", "task2b.o", argv[1], argv[2], argv[3], NULL);
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}