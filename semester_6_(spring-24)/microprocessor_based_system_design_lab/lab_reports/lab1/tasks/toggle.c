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
    while(1) {
        P1 = ~P1;   // Toggle all pins of Port 1
        P2 = ~P2;   // Toggle all pins of Port 2
        delay();    // Call delay function
    }
}
