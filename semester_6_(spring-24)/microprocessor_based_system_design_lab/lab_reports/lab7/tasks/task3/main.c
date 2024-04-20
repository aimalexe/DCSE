#include<reg51.h>

sbit MyBit = P1 ^ 1;
sbit I_Button = P1 ^ 2;

void startTimer(){
	TMOD = 0x01;
	IE = 0x82;
}

void timer0() interrupt 1{
	if(I_Button == 0){
		if(MyBit){
			TH0= 0xf0;
			TL0 = 0x5f;
		}
		else {
			TH0= 0xe8;
			TL0 = 0x8f;
		}
	}
	else{
		if(I_Button == 0){
			TH0 = 0xf8;
			TL0 = 0x43;
		}
		else {
			TH0 = 0xfc;
			TL0 = 0x03;
		}
	}
	MyBit = ~MyBit;	
}

void startTimer0(){
	TR0 = 1;
}

int main(){
	startTimer0();
	startTimer();
	I_Button = 1;
	
	while(1);
			
}