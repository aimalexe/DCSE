// Write a program that creates an array of size 100. Initialize the array with random numbers. Create 10 child processes divide the array between them. Each child will add the portion and return their sum to parent process. Parent will add the results and display a final sum.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define ARRAY_SIZE 100

int main(void)
{
    int array[ARRAY_SIZE] = {}, i = 0;

    // initialize array randomly
    for (; i < ARRAY_SIZE; i++)
        array[i] = rand() % 10;

    // create 10 processes and sum the parts
    pid_t pid;
    int status, sum = 0, processCount = ARRAY_SIZE / 10;
    for (i = 0; i < processCount; i++)
    {
        if ((pid = fork()) == -1)
        {
            perror("Error while creating a child process.\n");
            return 1;
        }
        else if (pid == 0)
        { // Child process
            int sum_child = 0, start = i * 10, end = start + 10, j;
            for (j = start; j < end; j++)
                sum_child += array[j];
            return sum_child;
        }
        else
        { // Parent Process.
            wait(&status);
            if (WIFEXITED(status))
                sum += WEXITSTATUS(status);
        }
    }
    printf("The Sum Is: %d \n", sum);
    return 0;
}

//? The return value of a process is limited to n bits, which means it can only accurately represent numbers between 0 and n. If sum_child exceeds this range, the value will be truncated, which will lead to incorrect sums.