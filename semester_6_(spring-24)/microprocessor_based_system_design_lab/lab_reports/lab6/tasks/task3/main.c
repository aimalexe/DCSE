#include <reg51.h>

sbit pin = P3 ^ 0;

void startTimer0(){ // Function to start timer 0.
	TR0 = 1;
}

void timer0() interrupt 1{ // using intterrupt 1 of timer 0.
	// 50 msec delay = 65535 - 50000 = 15535 or ffff - c350 = 3caf
	TH0 = 0x3c; // high byte of timer 0
	TL0 = 0xaf; // lower byte of timer 0
}

void startTimer(){ // 
	TMOD = 0x01; // using as a counter or timer
	IE = 0x82; // Enabling global interrupt(EA) and timer 0. 
}


void main(){
	startTimer0();
	startTimer();
	
	while(1){
		while(TF0 == 0);
		pin = ~pin;
	}		
}