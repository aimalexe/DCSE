#include <reg51.h>  // Include for 8051 register definitions

// Define keypad column pins
sbit Column0 = P2^6;
sbit Column1 = P2^5;
sbit Column2 = P2^4;

// Define keypad row pins
sbit Row0 = P2^0;
sbit Row1 = P2^1;
sbit Row2 = P2^2;
sbit Row3 = P2^3;

// Define LED control pins
sbit LED0 = P1^0;
sbit LED1 = P1^1;
sbit LED2 = P1^2;
sbit LED3 = P1^3;
sbit LED4 = P1^4;
sbit LED5 = P1^5;
sbit LED6 = P1^6;
sbit LED7 = P1^7;

void displaySegment(int segmentData);

void main(void)
{
    P1 = 0;  // Reset all P1 pins to 0
    Row1 = Row2 = 1;  // Set Row1 and Row2 to high
    Row0 = 0;  // Set Row0 to low

    // Check if Column0 is pressed
    if (Column0 == 0)
    {
        LED0 = 1;  // Turn on LED0
        displaySegment(0xF9);  // Display segment data for "F9"
    }

    // Check if Column1 is pressed
    if (Column1 == 0)
    {
        LED1 = 1;  // Turn on LED1
        displaySegment(0xA4);  // Display segment data for "A4"
    }

    // Check if Column2 is pressed
    if (Column2 == 0)
    {
        LED2 = 1;  // Turn on LED2
        displaySegment(0xB0);  // Display segment data for "B0"
    }
}

void displaySegment(int segmentData)
{
    P3 = 0x00;  // Clear P3
    P3 = segmentData;  // Set P3 to the segment data
}
