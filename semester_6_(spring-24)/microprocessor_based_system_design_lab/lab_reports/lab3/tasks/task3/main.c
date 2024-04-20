// Task 3: Attach 2 push button with PORT2 and 4 LED’s with PORT1 and turn ON led when the corresponding button are pressed, use polling for monitoring the buttons.

#include <reg51.h>
#include <stdio.h>

sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;

sbit switch1 = P2^0;
sbit switch2 = P2^1;

void main(void){
	while(1){
		if(!switch1 & !switch2){
			led1 = 1; led2 = 0;
			led3 = 0; led4 = 0;
		}	
		else if(!switch1 & switch2){
			led1 = 1; led2 = 1;
			led3= 0 ; led4 = 0;
		}
		else if(switch1 & !switch2){
			led1 = 1; led2 = 0;
			led3 = 0; led4 = 1;
		}	
		else if(switch1 & switch2){
			led1 = 1; led2 = 0;
			led3 = 1; led4 = 1;
		}
		else{
			led1 = 0; led2 = 0;
			led3 = 0; led4 = 0;
		}
	}
}