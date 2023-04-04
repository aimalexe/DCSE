/*
 *Create process fan as shown in figure 1 (a) and fill the figure 1 (a) with actual IDs.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	printf("I am parent and my Id is: %d.\n", getpid());

	int i, x, r;
	
	// Creating Childs
	for(i = 0 ; i < 8; i++){
	       	x = fork();
		if( x == 0) break;
       	}
	
	// Waiting for childs
	for(i = 0; i < 8; i++){
		if( x > 0){
			r = wait(NULL);
			printf("This is a Blade(child-%d) of fan(parent): %d.\n",i+1, r);
		}
	}
	
	return 0;
}
