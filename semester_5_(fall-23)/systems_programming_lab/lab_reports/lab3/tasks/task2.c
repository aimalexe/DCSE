//  Create process fan as shown in figure 3.1 (a) and fill the figure 3.1 (a) with actual IDs.

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
        else if (processId == 0)
            break;
        else if (processId > 0)
            printf("i = %d, ppid = %d, pid = %d.\n", count, getppid(), getpid());
    }
    return 0;
}