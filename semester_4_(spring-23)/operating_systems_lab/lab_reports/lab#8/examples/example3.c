/*
Multiple Threads: 
The simple example code below creates 5 threads with the pthread_create( ) routine.
Each thread prints a "Hello World!" message, and then terminates with a call to
pthread_exit( ).  
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *t)
{
    printf("\n%ld: Hello World!\n", pthread_self());
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc, t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, NULL);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL);
}