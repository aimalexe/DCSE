/*
 * Run the following program twice. Both times as a background process, i.e., suffix it with an ampersand "&".
 * Once both processes are running as background processes, view the process table using ps -l UNIX command.
 * Observe the process state, PID (process ID) etc. Repeat this experiment to observe the changes, if any.
 * Write your observation about the Process ID and state of the process.
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Process Id is: %d.\n", getpid());
	printf("Parent process Id is: %d.\n", getppid());
	sleep(8);
	printf("I am awake!\n");

	return 0;
}
