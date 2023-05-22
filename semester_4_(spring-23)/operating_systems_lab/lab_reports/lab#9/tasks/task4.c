/*
Problem # 4:
Write a program that passes a structure with at least two data members as an argument
to the thread function. Take the values as input in main function and display the data
members in thread function. Repeat for at least 3 child threads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Fan{
    int blades;
    int speed;
};

void *ChildThread(void *argument)
{
    struct Fan f = *(struct Fan *)argument;
    printf("Fan blades?  %d\n", f.blades);
    printf("Fan speed?  %d\n", f.speed);
}

int main(){
    int N = 3;
    struct Fan f[N];

    printf("Enter %d values in struct:\n", N);
    for(int i = 0; i < N; i++){
        printf("Enter number of blades in f[%d]? ", i);
        scanf("%d", &f[i].blades);
        printf("Enter speed of f[%d]? ", i);
        scanf("%d", &f[i].speed);
    }

    pthread_t threads[N];
    int rc;

    for (int i = 0; i < N; i++)
    {
        rc = pthread_create(&threads[i], NULL, ChildThread, (void *)&f[i]);
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
