#include <reg51.h>
#include <stdio.h>

sbit P_Button = P2^0;
sbit P_Led = P2^1;

sbit I_Button = P3^2;
sbit I_Led = P3^4;

int i = 0;

void eio() interrupt 0
{
	for(i = 0; i < 100; i++);
	I_Led ^= 1;
}

void main(void){
	P_Button = 1;
	I_Button = 1;
	
	EX0 = 1;
	EA = 1;
	IT0 = 1;
	
	while(1){
		if(!P_Button)
			P_Led = 1;
		else
			P_Led = 0;
	}
}