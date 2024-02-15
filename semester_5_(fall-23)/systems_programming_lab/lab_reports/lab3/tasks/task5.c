//  Write a program that takes N number of integers as argument and displays the factorials of N integers (print 1 only if integers are not less than zero, 0 or 1). separate child process for each integer. Make sure no child is orphan/zombie.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

long int factorial(int num)
{
    long int fact = 1;
    if (num == 0)
        return fact;
    else if (num < 0)
        return -1;
    else
    {
        for (int i = num; i > 0; i--)
            fact *= i;
        return fact;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s number1 [number2 ...]\n", argv[0]);
        return 1;
    }
    int status;
    pid_t processId;
    for (int i = 1; i < argc; i++)
    {
        if ((processId = fork()) == -1)
        {
            perror("Failed to create the child process");
            return 1;
        }
        else if (processId > 0)
        {
            wait(&status);
            if (WIFEXITED(status))
            {
                if (WEXITSTATUS(status) < 0)
                    printf("Cannot calculate factorial of negative number.\n");
                else
                    printf("%d! = %ld\n", atoi(argv[i]), (long)WEXITSTATUS(status));
            }
        }
        else if (processId == 0)
            return factorial(atoi(argv[i]));
    }
    return 0;
}

//? The return value of a process is limited to n bits, which means it can only accurately represent numbers between 0 and n. If factorial exceeds this range, the value will be truncated, which will lead to incorrect factorial.

//?  WEXITSTATUS(status) returns an unsigned char, so it can't represent negative numbers. If the factorial function returns -1, this value might not be correctly interpreted in the parent process.