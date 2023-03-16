/*
Write a program reads a number from user and finds its factorial using function. Pass the argument to function by value.
*/

#include <stdio.h>
int factorialOf(int num){
	int fact = 1;
	for( int i = 1; i <= num; i++){
		fact *= i;
	}
	return fact;
}

int main (void) {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	int fact = factorialOf(num);
	printf("The factorial of %d is %d\n", num, fact);

    return 0;
}

