#include <reg51.h>   // Include header file for 8051

// Define LCD control pins
sbit lcdRegisterSelect = P3^7;       // Register select pin for LCD
sbit lcdEnable = P3^6;               // Enable pin for LCD

// Define keypad row and column pins
sbit row1 = P1^0;
sbit row2 = P1^1;
sbit row3 = P1^2;
sbit row4 = P1^3;
sbit column1 = P1^4;
sbit column2 = P1^5;
sbit column3 = P1^6;

// Function prototypes
void delayMilliseconds(unsigned int ms);
void sendLcdCommand(unsigned char command);
void sendLcdData(unsigned char _data);
void initializeLcdDisplay(void);
unsigned char scanKeypad(void);
void displayNumberOnLcd(unsigned char number);

// Main function
int main() {
    unsigned char key;

    initializeLcdDisplay();  // Initialize the LCD display

    while (1) {
        key = scanKeypad();  // Read key from keypad
        if (key != ' ') {    // Check if a key is pressed
            displayNumberOnLcd(key);  // Display the number on LCD
        }
    }

    return 0;
}

// Implement a simple delay function
void delayMilliseconds(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 127; j++);
}

// Send a command to the LCD
void sendLcdCommand(unsigned char command) {
    lcdRegisterSelect = 0;  // Command mode
    P2 = command;           // Place command on the bus
    lcdEnable = 1;          // Pulse enable
    delayMilliseconds(1);
    lcdEnable = 0;
    delayMilliseconds(5);
}

// Send data to the LCD
void sendLcdData(unsigned char _data) {
    lcdRegisterSelect = 1;  // Data mode
    P2 = _data;              // Place data on the bus
    lcdEnable = 1;          // Pulse enable
    delayMilliseconds(1);
    lcdEnable = 0;
    delayMilliseconds(5);
}

// Initialize the LCD
void initializeLcdDisplay(void) {
    delayMilliseconds(15);
    sendLcdCommand(0x38);  // Function set: 2 Lines, 8-bit mode
    sendLcdCommand(0x0E);  // Display ON, cursor ON
    sendLcdCommand(0x01);  // Clear display
    sendLcdCommand(0x06);  // Entry mode set
}

// Function to read the keypad
unsigned char scanKeypad(void) {
    unsigned char keyMap[4][3] = {{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}, {' ', '0', ' '}};
    unsigned char row, col;

    for (row = 0; row < 4; row++) {
        P1 = ~(1 << row);  // Ground one row at a time

        for (col = 0; col < 3; col++) {
            if (!(P1 & (1 << (col + 4)))) {  // Check if column is low
                delayMilliseconds(20);       // Debounce delay
                while (!(P1 & (1 << (col + 4))));  // Wait for key release
                return keyMap[row][col];    // Return the corresponding key
            }
        }
    }

    return ' ';  // Return space if no key is pressed
}

// Display a number on the LCD
void displayNumberOnLcd(unsigned char number) {
    sendLcdCommand(0x80);  // Move cursor to the first line
    sendLcdData(number);   // Display the number
}
