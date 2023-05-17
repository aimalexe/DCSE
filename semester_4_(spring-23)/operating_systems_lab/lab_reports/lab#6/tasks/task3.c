//Create a fan of N processes. Take N as input from the user. Make sure there are no orphan processes.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int noOfProcesses;
	printf("Enter number of processes in a fan? ");
	scanf("%d", &noOfProcesses);
	if(noOfProcesses <= 0){
		printf("Invalid Entry\n");
		return 1;
	}

	pid_t parentId = getpid();
	pid_t childId;

	for(int i = 0; i < noOfProcesses; i++){
		childId = fork();
		if(childId < 0){
			printf("Processes creation failed");
			return 1;
		}
		else if(childId == 0){
			printf("Parent Id: %d, Child Id: %d.\n", getppid(), getpid());
			break;
		}
	}

	if(getpid() != parentId)
		wait(NULL);
	return 0;
}
