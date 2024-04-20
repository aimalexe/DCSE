// Task 2: Attach one push button with PORT2 and one LED with PORT1 and turn ON led when the corresponding button are pressed, use polling for monitoring the button.

#include <reg51.h>
#include <stdio.h>

sbit blueLed = P2 ^ 6;
sbit push = P1 ^ 2;

void main(void){
    while(1){
        if(push==1)
            blueLed = 1;
        else
            blueLed = 0;
    }
}

