/*
Problem # 2:
Write a program Box # 2 by removing pthread_exit function from child thread function and
check the output? Is it the same as output of Box # 1? If so Why? Explain?
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ChildThread(void* argument)
{
	int count = *(int *) argument;
	for(int i = 1; i <= count; i++)
		printf("Count: %d\n", i);
	//pthread_exit(NULL);
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
