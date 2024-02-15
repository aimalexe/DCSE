// Write a program that takes integers as arguments and adds them

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argCount, char *argNames[]){
	if(argCount <= 1){
		fprintf(stderr, "Usage: %s number1 [number2 ...]\n", argNames[0]);
		return 1;
	}

	printf("The file name is: %s\n", argNames[0]);
	int sum = 0;
	for(int i = 1; i < argCount; i++)
		sum += atoi(argNames[i]);

	printf("The sum of arguments are: %d\n", sum);

	return 0;
}
