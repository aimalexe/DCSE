#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;
	printf("Hello World! \n");
	printf("I am the parent process and my pid is: %d.\n", getpid());
	printf("Here I am before forking\n");

	pid = fork();

	printf("Here I am after forking.\n");
	if(pid == 0){
		printf("I am the child process and my pid is: %d.\n", getpid());
	}
	else{
		printf("I am the parent process and my pid is: %d.\n", getpid());
	}

	return 0;
}
