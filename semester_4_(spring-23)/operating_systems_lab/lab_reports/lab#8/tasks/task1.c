/*
Task 1:
The following Box #1 program demonstrates a simple program where the main thread
creates another thread to print out the numbers from 1 to 20. The main thread waits
till the child thread finishes.
*/

#include <pthread.h>
#include <stdio.h>

void *ChildThread(void *argument)
{
    for (int i = 1; i <= 20; ++i)
    {
        printf(" Child Count - %d\n", i);
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t hThread;
    int ret;

    ret = pthread_create(&hThread, NULL, (void *)ChildThread, NULL); /* Create
Thread */

    if (ret < 0)
    {
        printf("Thread Creation Failed\n");
        return 1;
    }

    pthread_join(hThread, NULL); /* Parent waits for  */

    printf("Parent is continuing....\n");

    return 0;
}
