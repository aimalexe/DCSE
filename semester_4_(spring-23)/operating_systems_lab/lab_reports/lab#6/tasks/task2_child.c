#include <stdio.h>
#include <unistd.h>

int main(){
	int arr[6] = { 3, 7, -8, 0, 3, 10};
	int max = arr[0];
	for(int i = 0; i < 6; i++)
		if(max < arr[i])
			max = arr[i];
	
	printf("The greatest number in array is: %d.\n", max);

	return 0;
}
