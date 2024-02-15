// Q-1)

/* 
Create process chain as shown in figure 3.1(b) and fill the figure 3.1 (b) with actual IDs. The program shall take a single command-line argument that specifies the number of processes to be created. Before exiting, each process shall output its i value (loop variable), its process ID (using getpid()), its parent process ID (getppid()) and the process ID of its child (return value of fork). The parent does not execute wait.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int childCount = atoi(argv[1]);
    for (int count = 0; count < childCount; count++)
    {
        int processId = fork();
        if (processId == -1)
            printf("Failed to create the child process");
        else if (processId > 0)
            break;
        else if (processId == 0)
            printf("i = %d, ppid = %d, pid = %d.\n", count, getppid(), getpid());
    }
    return 0;
}