#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argCount, char * argNames[]){
	pid_t x;
	printf("Parent: %d\n", getpid());
	//Creating fan process
	for(int i = 1; i < argCount; i++){
		x = fork();
		printf("Parent: %d --> Child: %d\n",getppid(), getpid() );
		if( x == 0){
			execlp("./task2.o", "task2.o", argNames[1], argNames[2], argNames[3], NULL);       
			break;
		}
	}

	//waiting for childs.
	for(int i = 1; i < argCount; i++){
		if(x > 0){
			int r = wait(NULL);
		}
	}	
	
	return 0;
}
