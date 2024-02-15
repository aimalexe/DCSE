//Write a program that takes N UNIX commands as arguments, creates N child processes, each of them implementing their respective commands. Parent process shall wait for all the child processes and receive and print the exit status of the child processes.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argCount, char * argNames[]){
	if(argCount <= 1){
		fprintf(stderr, "Usage: %s <list-of-unix-commands>\n", argNames[0]);
		return 1;
	}

	pid_t childProcess;
	pid_t parentProcess = getpid();

	printf("Parent Id: %d\n", parentProcess);

	//Creating fan process
	for(int i = 1; i < argCount; i++){
		childProcess = fork();
	
		if(childProcess < 0){
			printf("Process Creation Faild!!\n");
			return 1;
		}
		else if(childProcess == 0){
			printf("Parent Id: %d --> Child Id: %d\n",getppid(), getpid() );
			execlp(argNames[i], argNames[i], NULL);       
			break;
		}
	}

	//waiting for childs.
	if(getpid() == parentProcess)
		for(int i = 1; i < argCount; i++)
			wait(NULL);

	return 0;
}
