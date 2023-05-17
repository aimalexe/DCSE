//Task2:
//a.	Write a C program that finds the max of an array.
//b.	Write a C program that creates a child process and executes the above program in child process. Parent shall wait for the child process.

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	printf("Printing greater from parent\n");
	int pid = fork();

	if(pid == 0)
		execlp("./task2_child.o", "task2_child.o", NULL);
	else
		wait(NULL);

	return 0;
}
