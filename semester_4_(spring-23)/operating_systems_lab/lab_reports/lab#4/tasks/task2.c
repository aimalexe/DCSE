/*
Task 2: The following program demonstrates about the pointer variable, *  and & operators. Run and observe the output.
*/
#include <stdio.h>

int main(void){
	int num;
	int *p;

	printf("Enter a number: ");
	scanf("%d", &num);

	p = &num;

	printf("The value of variable is: %d \n", num);
	printf("The address of variable is: %p \n", &num);

	printf("The value of pointer is: %p\n", p);
	printf("The value pointed by p is: %d\n", *p);
	printf("The address of pointer is: %p\n", &p);

	return 0;
}
