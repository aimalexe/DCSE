//  Create process tree as shown in figure 3.2 and fill figure 3.2 with actual IDs.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void createProcessTree(int currentLevel, int maxLevel)
{
    if (currentLevel > maxLevel)
        return;

    pid_t pid1;
    if ((pid1 = fork()) == -1)
    {
        perror("Failed to create a child.\n");
        return;
    }

    else if (pid1 == 0)
    {
        // Child process
        printf("Level %d, PID: %d, Parent PID: %d\n", currentLevel, getpid(), getppid());
        createProcessTree(currentLevel + 1, maxLevel);
        _exit(0); // Terminate child process
    }
    else
    {
        // Parent process, create another child
        pid_t pid2;
        if ((pid2 = fork()) == -1)
        {
            perror("Failed to create a child.\n");
            return;
        }
        else if (pid2 == 0)
        {
            // Child process
            printf("Level %d, PID: %d, Parent PID: %d\n", currentLevel, getpid(), getppid());
            createProcessTree(currentLevel + 1, maxLevel);
            _exit(0); // Terminate child process
        }
        else
        {
            // Parent process waits for both children to prevent zombies
            wait(NULL);
            wait(NULL);
        }
    }
}

int main()
{
    printf("Root, PID: %d\n", getpid());
    createProcessTree(1, 4);
    return 0;
}
