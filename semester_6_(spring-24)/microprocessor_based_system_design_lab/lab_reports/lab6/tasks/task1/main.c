#include <reg51.h>

sbit pin = P3 ^ 0;

void startTimer0(){ // Function to start timer 0.
	TR0 = 1;
}

void timer0() interrupt 1{ // using intterrupt 1 of timer 0.
	//200 micro sec delay = 65535 - 200 = 65335 or ffff - 00c8 = ff37

	TH0 = 0xff; // high byte of timer 0
	TL0 = 0x37; // lower byte of timer 0
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