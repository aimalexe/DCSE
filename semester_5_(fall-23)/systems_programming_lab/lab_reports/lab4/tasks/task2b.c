// Write a program that takes integers as arguments and multiplies them

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argCount, char *argNames[]){
    if(argCount <= 1){
		fprintf(stderr, "Usage: %s number1 [number2 ...]\n", argNames[0]);
		return 1;
	}

	printf("The file name is: %s\n", argNames[0]);
	int product = 1;
	for(int i = 1; i < argCount; i++)
		product *= atoi(argNames[i]);
	printf("The product of arguments are: %d\n", product);

	return 0;
}
