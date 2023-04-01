#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(){
	
	int x = close(5);
	if ( x == -1){
		perror("Failed to close! \n");
		return -1;
	}
	return 0;
}
