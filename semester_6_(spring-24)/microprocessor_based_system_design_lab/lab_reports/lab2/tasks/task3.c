#include <reg51.h>  // Include the 8051 register definitions

void delay() {
    unsigned int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            // Adjust these loops based on your clock frequency for proper delay
        }
    }
}

void main() {
    unsigned char pattern = 0x01;  // Initialize pattern
    unsigned char i;

    while(1) {
        P1 = pattern;  // Display pattern on Port 1
        delay();       // Call delay function
        pattern = pattern << 1;  // Shift pattern to left
        if (pattern == 0)        // If pattern is 0, reset it to 1
            pattern = 0x01;

        for (i = 0; i < 8; i++) {   // Loop to display pattern on Port 2
            P2 = pattern;
            delay();
        }
    }
}
