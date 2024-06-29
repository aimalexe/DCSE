#include<reg51.h>

unsigned int i, j, k;

void delay(unsigned int milliSecond){
	for(i = 0; i < milliSecond; i++)
		for(j = 0; j < 1225; j++);
}

int main(){
		for(k = 0; 1; k++){
			if(k==0x0A )
				k = 0x00;
			P2 = k; // send the lower bit to display the count	
			delay(40);
		}
}