//Task4: Create a chain of N processes. Take N as input from user. Make sure there are no orphan processes.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int numOfProcesses;
	printf("Enter how many chains of processes do you want? ");
	scanf("%d", &numOfProcesses);
	
	if(numOfProcesses <= 0){
		printf("Invalid Number\n");
		exit(1);
	}
	
	pid_t parentProcess = getpid();
	pid_t childProcess;
	
	for(int i = 0; i < numOfProcesses; i++){
		childProcess = fork();
		if(childProcess < 0){
			printf("Cann't create process\n");
			return 1;
		}
		else if(childProcess == 0){
			printf("Parent Id: %d, Child Id: %d.\n", getppid(), getpid());
		}
		else{
			wait(NULL);
			break;
		}
	}

	if(getpid() != parentProcess)
		wait(NULL);

	return 0;
}
