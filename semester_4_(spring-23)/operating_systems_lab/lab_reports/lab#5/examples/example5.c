#include <stdio.h>
#include<unistd.h>

int main(){
	int pid;
	
	printf("I am orignal process with pid: %d and ppid: %d.\n", getpid(), getppid());
	
	pid = fork();

	if(pid != 0){
		printf("I am the parent process with pid: %d and ppid: %d.\n", getpid(), getppid());
		printf("My child pid is: %d.\n", pid);
	}
	else {
		sleep(5);
		printf("I am the child process with pid: %d and ppid: %d.\n", getpid(), getppid());
	}
	printf("PID: %d terminated.\n", getpid());
	
	return 0;
}
