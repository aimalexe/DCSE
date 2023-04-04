/*
 * Run the following program and observe the result of time slicing used by UNIX.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int i = 0, j = 0, k, x;
	pid_t pid;
	
	if( pid == 0)
		for( ; i < 20; i++)
			for(k = 0; k < 50; k++)
				printf("Child: %d.\n", i);
	else
		for( ; j < 20; j++)
			for(x = 0; x < 50; x++)
				printf("Parent: %d.\n", j);
	
	return 0;
}
