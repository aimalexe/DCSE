#include <stdio.h>

int main(int argc, char *argv[]){
	/*
	 *First argument of main is argc which shows us the number of arguments passed. It will always show 1 because
	* the name of file will always be passed.
	*
	* The second argument is argv which shows the name of arguments. The first will be file name as argv[0] = ["f", "i", "l", "e", ".o", '\0']
	* the other will store the name of arguments passed.
	 */

	printf("Number of arguments are: %d\n", argc);
	printf("File name is: %s\n", argv[0]);
	printf("The arguments passed are\n");
	for(int i = 1; i < argc; i++){
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	return 0;
}
