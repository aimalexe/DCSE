#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int i, x, r, blades;
	
	printf("Enter a number to create processes? \n");
	scanf("%d", &blades);

	for(i = 0 ; i < blades; i++){
	       x = fork();
	       if( x == 0) break;
	}

	for(i = 0; i < blades; i++)
		if( x > 0){
			r = wait(NULL);
			printf("This is a Blade of fan: %d.\n", r);
		}
			

	return 0;
}
