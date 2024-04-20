#include <reg51.h>
#include <stdio.h>

void delay(void){
	int i;
	for(i=0; i<30000; i++);
	for(i=0; i<30000; i++);
	for(i=0; i<30000; i++);
}

void main(void){
	P1 = 0x00; 
	//LED Segments: 1gfe_dcba
	
	while(1){
		P1 = 0xC0; // 0: 1100 0000
		delay();
		
		P1 = 0xF9; // 1: 1111 1001
		delay();
		
		P1 = 0xA4; // 2: 1010 0100
		delay();
		
		P1 = 0xB0; // 3: 1011 0000
		delay();
		
		P1 = 0x99; // 4: 1001 1001
		delay();
		
		P1 = 0x92; // 5: 1001 0010
		delay();
		
		P1 = 0x82; // 6: 1000 0010
		delay();
		
		P1 = 0xf8; // 7: 1111 1000
		delay();
		
		P1 = 0x80; // 8: 1000 0000
		delay();
		
		P1 = 0x90; // 9: 1001 0000
		delay();
		
		P1 = 0x88; // A: 1000 1000
		delay();
		
		P1 = 0x83; // B: 1000 0011
		delay();
		
		P1 = 0xC6; // C: 1100 0110
		delay();
		
		P1 = 0xA1; // D: 1010 0001
		delay();
		
		P1 = 0x86; // E: 1000 0110
		delay();
		
		P1 = 0x8E; // F: 1000 1110
		delay();		
	}
}