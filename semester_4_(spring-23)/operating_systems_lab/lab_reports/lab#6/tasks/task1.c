//Task1:
//Write a C program that executes ls -l command in the child process. Parent process shall wait for the child process.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	printf("Executing another file as child froml parent\n");
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("Hello\n");
		//execlp("/usr/bin/ls", "ls -l", NULL);
		execlp("./task1_child.o", "task1_child.o", NULL);
	}
	else
		wait(NULL);
	return 0;
}
