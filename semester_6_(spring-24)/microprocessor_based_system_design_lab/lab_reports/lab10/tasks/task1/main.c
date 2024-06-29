#include <reg51.h>  // Include header file for 8051 microcontroller

sbit registerSelect = P3^7;  // Register select pin for LCD
sbit enable = P3^6;          // Enable pin for LCD

// Function prototypes
void delayMilliseconds(unsigned int milliseconds);
void sendLcdCommand(unsigned char command);
void sendLcdData(unsigned char _data);
void initializeLcd(void);
void displayString(char *string);

// Main function
int main() {
    initializeLcd();  // Set up the LCD display

    sendLcdCommand(0x80);  // Position cursor at the beginning of the first line
    displayString("Aimal Khan");  // Display name

    sendLcdCommand(0xC0);  // Position cursor at the beginning of the second line
    displayString("21PWCSE1996");  // Display registration number

    while(1);  // Loop indefinitely to maintain display
    return 0;
}

// Implement a delay function for specified milliseconds
void delayMilliseconds(unsigned int milliseconds) {
    unsigned int i, j;
    for (i = 0; i < milliseconds; i++)
        for (j = 0; j < 127; j++);
}

// Function to send a command to the LCD
void sendLcdCommand(unsigned char command) {
    registerSelect = 0;
    P2 = command;
    enable = 1;
    delayMilliseconds(1);  // Short delay for command processing
    enable = 0;
    delayMilliseconds(5);  // Ensure command execution
}

// Function to send data (characters) to the LCD
void sendLcdData(unsigned char _data) {
    registerSelect = 1;
    P2 = _data;
    enable = 1;
    delayMilliseconds(1);  // Short delay for data processing
    enable = 0;
    delayMilliseconds(5);  // Ensure data is displayed
}

// Function to initialize the LCD to desired settings
void initializeLcd(void) {
    sendLcdCommand(0x38);  // 8-bit mode, 2 line, 5x7 format
    sendLcdCommand(0x0E);  // Display ON, cursor blinking
    sendLcdCommand(0x01);  // Clear display screen
    sendLcdCommand(0x06);  // Cursor moves right, no shifting of display
    delayMilliseconds(5);  // Delay to allow LCD to finish initializing
}

// Function to display strings on the LCD
void displayString(char *string) {
    while (*string) {
        sendLcdData(*string++);
    }
}