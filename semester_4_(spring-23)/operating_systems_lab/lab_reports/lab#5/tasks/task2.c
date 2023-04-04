/*
 * Run the following program and observe the number of times and the order in which the print statement is executed.
 * The fork( ) creates a child that is a duplicate of the parent process. The child process begins from the fork( ).
 * All the statements after the call to fork ( ) are executed by the parent process and also by the child process.
 * Draw a family tree of processes and explain the results you observed.
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	fork();

	printf("Parent process Id: %d.\n", getppid());

	return 0;
}
