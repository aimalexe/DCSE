//take list of command as CLA's. Execute each as seperate Process.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argCount, char * argNames[]){
	if(argCount <= 1){
		printf("No arguments provided!\n");
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
