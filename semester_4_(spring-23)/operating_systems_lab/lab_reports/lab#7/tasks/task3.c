// Execute task1.c through child process from this task.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argCount, char * argVal[]){
	if(argCount <= 1){
		printf("No arguments provided.\n");
		return 1;
	}
	else if(argCount > 4){
		printf("Arguments exceeded than 3. Please enter only 3 arguments.\n");
		return 1;
	}

	pid_t childId = fork();
	
	if(childId < 0){
		printf("Forking failed!\n");
		return 1;
	}
	else if(childId == 0){
		execlp("./task1.o", "task1.o", argVal[1], argVal[2], argVal[3], NULL);
		exit(1);
	}

	if(childId > 0)
		wait(NULL);


	return 0;
}
