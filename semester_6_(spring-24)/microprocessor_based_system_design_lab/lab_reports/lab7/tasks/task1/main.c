#include <reg51.h>

sbit PWM_Pin = P1 ^ 1; // PWM output on Pin P1.1 for the diagram only.

void Timer0_ISR() interrupt 1 {
    static unsigned char pwm_state = 0; // State tracking: 0 for low, 1 for high

    TR0 = 0; // Stop Timer 0
    if (pwm_state == 0) {
        PWM_Pin = 1; 
        TH0 = 0xFC; // Load timer high byte for high duration
        TL0 = 0x70; // Load timer low byte for high duration
        pwm_state = 1;
    } else {
        PWM_Pin = 0; 
        TH0 = 0xFB; 
        TL0 = 0x50; 
        pwm_state = 0;
    }
    TR0 = 1;
}

void main() {
    TMOD = 0x01; // Timer 0 in mode 1 (16-bit timer mode)
    TH0 = 0xFC; 
    TL0 = 0x70; 
    ET0 = 1; // Enable Timer 0 interrupt
    EA = 1; // Enable global interrupts
    TR0 = 1; // Start Timer 0

    while (1) ;
}
