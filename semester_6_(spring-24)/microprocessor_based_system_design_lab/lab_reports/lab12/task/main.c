#include <reg51.h>
#include <stdio.h>

#define BUTTON P3_2  // Assuming button is connected to P3.2

void delay(unsigned int millisecond){
    unsigned int i, j;
    for (i=0;i<millisecond;i++)
        for(j=0; j < 1000; j++);
}

void sine_wave(){
    int sine[] = {128,156,192,226,238,255,238,226,192,128,64,32,6,4,0,16,32,64};
    int i;
    for (i=0;i<18;i++){
        P1 = sine[i];
        delay(3);
    }
}

void triangle_wave(){
    unsigned int i;

    // Incremental part of the triangle wave
    for (i = 0; i < 255; i++) {
        P1 = i;  // Assuming P1 is 8-bit
        delay(2);  // Adjust delay to control the speed of the waveform
    }

    // Decremental part of the triangle wave
    for (i = 255; i > 0; i--) {
        P1 = i;  // Assuming P1 is 8-bit
        delay(2);  // Adjust delay to control the speed of the waveform
    }
}

void square_wave(){
  int k;  
	for (k = 0; k < 100; k++) {  // Run the square wave for 100 cycles
        P1 = 0xFF;  // Set P1 to high
        delay(50);  // High duration
        P1 = 0x00;  // Set P1 to low
        delay(50);  // Low duration
    }
}

void setup_interrupts() {
    IT0 = 1;  // Configure interrupt 0 for falling edge trigger
    EX0 = 1;  // Enable external interrupt 0
    EA = 1;   // Enable global interrupts
}

void external0_isr(void) interrupt 0 {
    static unsigned int wave_selector = 0;
    switch (wave_selector % 3) {
        case 0:
            sine_wave();
						wave_selector++;
            break;
        case 1:
            triangle_wave();
						wave_selector++;
            break;
        case 2:
            square_wave();
						wave_selector = 0;
            break;
    }
}

void main(void){
    setup_interrupts();
    while(1){
		square_wave();
		}
}
