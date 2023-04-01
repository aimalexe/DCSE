#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Here I am just before first forking system.\n");
	fork();

	printf("Here I am just after first forking system.\n");
	fork();

	printf("Here I am just after second forking system.\n");
	fork();

	printf("Here I am just after third forking system.\n");
	fork();


	return 0;
}
