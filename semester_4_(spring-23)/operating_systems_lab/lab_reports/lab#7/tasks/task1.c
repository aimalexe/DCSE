// Sum of all CLA's

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argCount, char *argNames[]){
	printf("The file name is: %s\n", argNames[0]);
	int sum = 0;
	for(int i = 1; i < argCount; i++){
		sum = sum + atoi(argNames[i]);
	}
	printf("The sum of arguments are: %d\n", sum);

	return 0;
}
