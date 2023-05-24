/*
Pthread Creation and Termination:

- Question: Do the threads have separate copies of glob_data? Why? Or why not?
*/

#include <stdio.h>
#include <pthread.h>

int glob_data = 5;

void *kidfunc(void *p)
{
    printf("Kid here. Global data was %d.\n", glob_data);
    glob_data = 15;
    printf("Kid Again. Global data is now %d.\n", glob_data);
}

void main()
{
    pthread_t kid;

    pthread_create(&kid, NULL, kidfunc, NULL);
    printf("Master thread here. Global data = %d\n", glob_data);
    glob_data = 10;
    pthread_join(kid, NULL);
    printf("End of program. Global data = %d\n", glob_data);
}
