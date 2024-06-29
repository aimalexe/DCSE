#include <reg51.h>

sbit PWM_Pin = P1 ^ 3; // PWM output on Pin P1.3

void Timer0_ISR() interrupt 1 {
    static unsigned char pwm_state = 0;

    TR0 = 0; // Stop Timer 0
    if (pwm_state == 0) {
        // Currently in low state, switch to high
        PWM_Pin = 1; // Set pin high
        TH0 = 0xFC;
        TL0 = 0x18; 
        pwm_state = 1;
    } else {
        // Currently in high state, switch to low
        PWM_Pin = 0; // Set pin low
        TH0 = 0xFC; 
        TL0 = 0xC5; 
        pwm_state = 0; // Update state to low
    }
    TR0 = 1; // Start Timer 0
}

void main() {
    TMOD = 0x01; 
    TH0 = 0xFC; // Initial load for timer high byte (for first high period)
    TL0 = 0x18; // Initial load for timer low byte (for first high period)
    ET0 = 1; 
    EA = 1; 
    TR0 = 1;

    while (1) ;
}
