#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

sigset_t set;
void myWait(void);

int main(void)
{
    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigprocmask(SIG_BLOCK, &set, NULL);

    pid_t pid = fork();
    if(pid < 0){
        return 1;
    }
    else if (pid > 0){
        myWait();
    }
    return 0;
}

void myWait(void)
{
    int x;
    sigwait(&set, &x); // Wiat for blocked signal.
    printf("Child is terminated by receiving signal number: %d.\n", x);
}