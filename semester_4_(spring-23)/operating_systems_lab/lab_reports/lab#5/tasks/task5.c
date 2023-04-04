/*
 *Create process chain as shown in figure 1(b) and fill the figure 1 (b) with actual IDs.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	printf("I am parent and my Id is: %d. My parent Id is: %d.\n", getpid(), getppid());
	pid_t pid;
	int retId;
	
	pid = fork(); //Creating first child.

	for(int i = 0; i < 6; i++){
		if(pid == 0){ // Child
			printf("I am a child - %d and my Id is: %d, My parent Id is: %d.\n",i + 1, getpid(), getppid() );
			pid = fork(); //creating next child.
		}
		else if(pid < 0){ // Error
			printf("Error: Faild to fork!\n");
			return -1;
		}
		else{	// Parent
			wait(NULL);
			break;
		}

	}
	return 0;
}
