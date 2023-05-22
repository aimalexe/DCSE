// Example: pthread_create( ) argument passing :

#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <pthread.h>

#define NUM_THREADS 7

char *message[NUM_THREADS];

void *PrintHello(void *threadid)
{
	int *id_ptr, taskId;
	sleep(1);
	id_ptr = (int *)threadid;
	taskId = *id_ptr;
	printf("\n %s from thread %d \n\n", message[taskId], taskId);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int *taskIds[NUM_THREADS];
	int rc, t;

	message[0] = "English: Hello World!";
	message[1] = "French: Bonjour, le monde!";
	message[2] = "Spanish: Hola al mondo!";
	message[3] = "Klingon: Nuq neh!";
	message[4] = "Pushto: Pakhair Malgari!";
	message[5] = "German: Guten tag welt!";
	message[6] = "Russian: Zdravstvytye, mir!";
	message[7] = "Japan: Sekai e konnichiwa!";

	for (t = 0; t < NUM_THREADS; t++)
	{
		taskIds[t] = (int *)malloc(sizeof(int));
		*taskIds[t] = t;
		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)taskIds[t]);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}
