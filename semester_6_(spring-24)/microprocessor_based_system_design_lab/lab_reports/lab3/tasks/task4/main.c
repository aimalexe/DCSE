// Task 4: Attach 3 push button with PORT2 and 8 LED’s with PORT1 and turn ON led when the corresponding button are pressed, use polling for monitoring the buttons.

#include <reg51.h>
#include <stdio.h>

sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;
sbit led5 = P2^4;
sbit led6 = P2^5;
sbit led7 = P2^6;
sbit led8 = P2^7;

sbit switch1 = P1^0;
sbit switch2 = P1^1;
sbit switch3 = P1^2;

void main(void){
		while(1){
			if(!switch1 & !switch2 & !switch3){
				led1 = 1; led2 = 0;
				led3 = 1; led4 = 0;
				led5 = 1; led6 = 0;
				led7 = 1; led8 = 0;
			}
			else if(!switch1 & !switch2 & switch3){
				led1 = 0; led2 = 1;
				led3 = 0; led4 = 1;
				led5 = 0; led6 = 1;
				led7 = 0; led8 = 1;
			}
			else if(!switch1 & switch2 & !switch3){
				led1 = 1; led2 = 1;
				led3 = 0; led4 = 0;
				led5 = 1; led6 = 1;
				led7 = 0; led8 = 0;
			}
			else if(!switch1 & switch2 & switch3){
				led1 = 0; led2 = 0;
				led3 = 1; led4 = 1;
				led5 = 0; led6 = 0;
				led7 = 1; led8 = 1;
			}
			else if(switch1 & !switch2 & !switch3){
				led1 = 1; led2 = 0;
				led3 = 1; led4 = 0;
				led5 = 1; led6 = 0;
				led7 = 0; led8 = 1;
			}
			else if(switch1 & !switch2 & switch3){
				led1 = 0; led2 = 0;
				led3 = 0; led4 = 1;
				led5 = 0; led6 = 1;
				led7 = 1; led8 = 1;
			}
			else if(switch1 & switch2 & !switch3){
				led1 = 1; led2 = 1;
				led3 = 1; led4 = 1;
				led5 = 0; led6 = 0;
				led7 = 0; led8 = 0;
			}
			else if(switch1 & switch2 & switch3){
				led1 = 0; led2 = 0;
				led3 = 0; led4 = 0;
				led5 = 1; led6 = 1;
				led7 = 1; led8 = 1;
			}
			else{
				led1 = 0; led2 = 0;
				led3 = 0; led4 = 0;
				led5 = 0; led6 = 0;
				led7 = 0; led8 = 0;
			}
	}
}