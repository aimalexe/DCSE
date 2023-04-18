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
