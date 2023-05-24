/*
Task2:
Write a program Box # 2 by removing pthread_exit function from child thread function
and check the output? Is it the same as output when pthread_exit is used? If so Why?
Explain?
*/

#include <pthread.h>
#include <stdio.h>

void* ChildThread1(void* argument)
{
    printf("In a thread with pthread_exit(0)\n");
    pthread_exit(0);
}

void* ChildThread2(void* argument)
{
    printf("In a thread with no pthread_exit(0)\n");
}

int main(void)
{
    pthread_t thread1, thread2;

    int r1, r2;

    r1 = pthread_create(&thread1, NULL, ChildThread1, NULL);
    r2 = pthread_create(&thread2, NULL, ChildThread2, NULL);

    if(r1 < 0 || r2 < 0){
        printf("Threads creation failed!\n");
        return 1;
    }
    
    //Waiting for threads to complete.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Master thread is continuing....\n");
    return 0;
}
