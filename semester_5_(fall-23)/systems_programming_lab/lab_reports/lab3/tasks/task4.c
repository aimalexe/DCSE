// Creates a chain of processes. It takes a single command-line argument that specifies the number of processes to create. Before exiting, each process outputs its i value, its process ID, its parent process ID, and the process ID of its child. The parent does not execute wait. If the parent exits before the child, the child becomes an orphan. In this case, the child process is adopted by a special system process (which traditionally is a process, init, with process ID of 1). As a result, some of the processes may indicate a parent process ID of 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number of processes>\n", argv[0]);
        return 1;
    }

    int num_processes = atoi(argv[1]);
    if (num_processes <= 0)
    {
        fprintf(stderr, "The number of processes must be a positive integer\n");
        return 1;
    }

    pid_t pid, child_pid = 0;
    for (int i = 0; i < num_processes; ++i)
    {
        pid = fork();
        if ((pid = fork()) < 0)
        {
            perror("Failed to create a child. \n");
            return 1;
        }
        else if (pid > 0)
        { // Parent process
            child_pid = pid;
            break;
        }
        else
        {
            // Child process continues the loop
            // Each process outputs its information before exiting
            printf("PID = %d, Parent PID = %d, Child PID = %d\n", getpid(), getppid(), child_pid);
        }
    }

    // Exit normally
    return 0;
}
