#include<reg51.h>

sbit pushButton = P3 ^ 4;


void initTimer(){
	TMOD = 0x06; // use timer as a counter
	TH0 = 0; // use to count upto 0xff.
	TL0 = 0;
	pushButton = 1;
}
void startTimer(){
	TR0 = 1; // use timer 0
}


int main(){
	startTimer();
	initTimer();
	
	while(1){
		P2 = TL0; // send the lower bit to display the count	
	}
}