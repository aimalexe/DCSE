/*
Task 4: Write a function that calculates the dot product of two dimensional array. Call this function from main() function and display the product.
*/
#include <stdio.h>

int dotProductOf(int arr[3][3]){
	int result = 1;

	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			result = result * arr[i][j];
	return result;
}

int main(void){
	int arr1[3][3] = {{1,2, 9},{3,4, 3}, {5, 6, 8}};
	int prod = dotProductOf(arr1);
	printf("The dot product of the array is: %d\n", prod);
	return 0;
}
