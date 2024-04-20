#include <reg51.h>

sbit pin = P3 ^ 0;

void startTimer0(){ // Function to start timer 0.
	TR0 = 1;
}

void timer0() interrupt 1{ // using intterrupt 1 of timer 0.
	// 15 msec delay = 65535 - 15000 = 50535 or ffff - 3a98 = c567
	TH0 = 0xC5; // high byte of timer 0
	TL0 = 0x67; // lower byte of timer 0
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