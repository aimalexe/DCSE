/*
Problem # 1:
Modify the above Box #1 program such that the main program passes the count as argument
to the child thread function and the child thread function prints that many count print
statements.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ChildThread(void* argument)
{
	int count = *(int *) argument;
	for(int i = 1; i <= count; i++)
		printf("Count: %d\n", i);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thread;
	int count = 5;

	pthread_create(&thread, NULL, ChildThread, (void *) &count);
	pthread_join(thread, NULL);

	printf("Parent is continuing....\n");
	return 0;
}
