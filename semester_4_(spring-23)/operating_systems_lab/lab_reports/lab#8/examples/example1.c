/*
Pthread Creation and Termination:

- Question: Are the process id numbers of parent and child thread the same or
different? Give reason(s) for your answer.
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *kidfunc(void *p)
{
    printf("Kid ID is ---> %d\n", getpid());
}

int main()
{
    pthread_t kid;
    pthread_create(&kid, NULL, kidfunc, NULL);
    printf("Parent ID is ---> %d\n", getpid());
    pthread_join(kid, NULL);
    printf("No more kid!\n");

    return 0;
}