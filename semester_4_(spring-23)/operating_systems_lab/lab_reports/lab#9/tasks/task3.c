/*
Problem # 3:
Write a program that creates N child threads in for loop. Pass the value of loop variable
as argument to thread function. Analyze the output and give reasons for the output you
observe.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ChildThread(void *argument)
{
    int index = *(int *)argument;
    printf("Argument passed is: %d\n", index);
}

int main(void)
{
    int N;
    printf("Enter 'N' to create 'N' threads? ");
    scanf("%d", &N);

    pthread_t threads[N];
    int rc;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
        rc = pthread_create(&threads[i], NULL, ChildThread, (void *)&arr[i]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);
    printf("Parent is continuing....\n");
    return 0;
}
