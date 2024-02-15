#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

sigset_t set;
void myHandler(int);
void myWait(void);

int main(void)
{
    struct sigaction newAction;
    newAction.sa_handler = myHandler;
    newAction.sa_flags = 0;

    sigfillset(&set);
    sigdelset(&set, SIGINT); // Only for debugging
    sigprocmask(SIG_BLOCK, &set, NULL);

    sigaction(SIGCHLD, &newAction, NULL);
    pid_t pid = fork();
    if(pid < 0){
        return 1;
    }
    else if( pid == 0){
        return 13;
    }
    else{
        myWait();
        return 0;
    }
}

void myHandler(int signo)
{
    printf("Child is terminated by receiving signal number: %d.\n", signo);
}

void myWait(void)
{
    sigdelset(&set, SIGCHLD);
    sigprocmask(SIG_SETMASK, &set, NULL);
    pause();
}