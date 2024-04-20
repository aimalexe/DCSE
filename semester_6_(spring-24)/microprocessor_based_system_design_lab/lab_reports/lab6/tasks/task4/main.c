#include <reg51.h>

sbit pin = P3 ^ 0;
int count = 0;

void startTimer0(){ // Function to start timer 0.
	TR0 = 1;
}

void timer0() interrupt 1{ // using intterrupt 1 of timer 0.
	// 300 msec delay = 60k * 5 times

	count++;
	if(count == 5){
		pin = ~pin;
		count = 0;
	}
	
	//delay = 65535 - 60000 = 5535 or ffff - ea60 = 159f
	TH0 = 0x15; // high byte of timer 0
	TL0 = 0x9f; // lower byte of timer 0
}

void startTimer(){ // 
	TMOD = 0x01; // using as a counter or timer
	IE = 0x82; // Enabling global interrupt(EA) and timer 0. 
}


void main(){
	startTimer0();
	startTimer();

	while(1);		
}