#include <reg51.h>
#include <stdio.h>

sbit I_Button = P3^2;

int count = 1;
int i;

void eio() interrupt 0
{
	for(i = 0; i < 100; i++);

	if(count == 15)
		count = 0;
	else
		count += 1;
	
	P1 = count;
}

void main(void){
	//leds = Led0 | Led1 | Led2 | Led3;
	EX0 = 1;
	IT0 = 1;
	EA = 1;

	I_Button = 1;
	
	while(1);
}