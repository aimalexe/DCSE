#include <reg51.h>   // Include header file for 8051

// Define control pins for LCD and ADC
sbit lcdRegisterSelect = P3^7;  // Register select pin for LCD
sbit lcdEnable = P3^6;          // Enable pin for LCD
sbit adcReadControl = P3^4;     // ADC read control
sbit adcWriteControl = P3^5;    // ADC write control
sbit adcInterrupt = P3^2;       // ADC interrupt pin

// Function prototypes
void delay(unsigned int milliseconds);
void sendLcdCommand(unsigned char command);
void sendLcdData(unsigned char lcdData);
void initializeLcd(void);
void displayRegistrationNumber(void);
unsigned char readAdcValue(void);
void displayTemperature(unsigned char adcValue);

// Main function
int main() {
    initializeLcd();
    while (1) {
        displayTemperature(readAdcValue());
        delay(5);     // Refresh the temperature display every 50 milliseconds
    }
    return 0;
}

// Implement delay function
void delay(unsigned int milliseconds) {
    unsigned int i, j;
    for (i = 0; i < milliseconds; i++)
        for (j = 0; j < 127; j++); // Fine-tune this based on your clock frequency
}

// Implement command writing to LCD
void sendLcdCommand(unsigned char command) {
    lcdRegisterSelect = 0;
    P2 = command;
    lcdEnable = 1;
    delay(1);
    lcdEnable = 0;
    delay(1);
}

// Implement data writing to LCD
void sendLcdData(unsigned char lcdData) {
    lcdRegisterSelect = 1;
    P2 = lcdData;
    lcdEnable = 1;
    delay(1);
    lcdEnable = 0;
    delay(1);
}

// Initialize LCD
void initializeLcd(void) {
    delay(15);                  // Wait for LCD to power up
    sendLcdCommand(0x38);       // Function set: 2 Lines, 8-bit mode
    sendLcdCommand(0x0E);       // Display ON, Cursor ON
    sendLcdCommand(0x01);       // Clear display
    sendLcdCommand(0x06);       // Entry mode set
}

// Display the registration number
void displayRegistrationNumber(void) {
    sendLcdCommand(0x80);  // Cursor to first row
    sendLcdData('2');  // Display registration number "21PWCSE1996"
    sendLcdData('1');
    sendLcdData('P');
    sendLcdData('W');
    sendLcdData('C');
    sendLcdData('S');
    sendLcdData('E');
    sendLcdData('1');
    sendLcdData('9');
    sendLcdData('9');
    sendLcdData('6');
}


// Read ADC value
unsigned char readAdcValue(void) {
    unsigned char adcValue;
    adcWriteControl = 0;
    delay(5);
    adcWriteControl = 1;
    while (adcInterrupt == 1);  // Wait for ADC conversion to complete
    adcReadControl = 0;
    adcValue = P1;              // Read ADC result
    delay(10);
    return adcValue;
}

// Display temperature with detailed formatting
void displayTemperature(unsigned char adcValue) {
    unsigned char unitDigit = 0;
    unsigned char tenthDigit = 0;
    unsigned char hundDigit = 0;
    unsigned char decimalDigit = 0;
    int point = adcValue * 10;
    
    decimalDigit = point % 10;
    hundDigit = (point / 100) % 10;
    tenthDigit = (point / 10) % 10;
    
    sendLcdCommand(0x01);  // Clear the display before displaying new temperature
		displayRegistrationNumber();
    sendLcdCommand(0xC0);  // Move cursor to the second line

    if (hundDigit != 0) {
        sendLcdData(hundDigit + '0');
    }
    if (tenthDigit != 0 || hundDigit != 0) {  // Only display if non-zero or not leading zero
        sendLcdData(tenthDigit + '0');
    }
    sendLcdData(unitDigit + '0');
    sendLcdData('.');
    sendLcdData(decimalDigit + '0');
		sendLcdData(' ');
    sendLcdData('C');  // Display unit
}
