#include <reg51.h>  // Include for 8051 register definitions
#include <stdio.h>

// Define keypad column pins
sbit Column0 = P2^6;
sbit Column1 = P2^5;
sbit Column2 = P2^4;

// Define keypad row pins
sbit Row0 = P2^0;
sbit Row1 = P2^1;
sbit Row2 = P2^2;
sbit Row3 = P2^3;

void displaySegment(int segmentData);
int calculateLEDs(int row, int col);

void main(void){
    int row, col, number;
    while(1){
        for(row = 0; row < 4; row++){  // Scan each row
            P2 = ~(1 << row);  // Activate current row
            for(col = 0; col < 3; col++){  // Check each column in the activated row
                if (!(P2 & (0x40 >> col))){  // Check if a button is pressed (P2^6 is Column0, P2^5 is Column1, P2^4 is Column2)
                    // Map the row and column to the correct number (1-9 and 0)
                    if(row == 3) {// special row 
                        switch(col) {
                            case 0:  // '*'
                                number = 10;  // Use the last index for '-'
                                P1 = 0x80;  // Turn on LED7
                                break;
                            case 1:  // '0'
                                number = 0;
                                P1 = calculateLEDs(row, col);
                                break;
                            case 2:  // '#'
                                number = 10; 
                                P1 = 0x80;
                                break;
                            default:
                                continue;
                        } 
                    } 
										else {
                        number = row * 3 + col + 1;
                        if(number >= 10) continue;  // Skip if the computed number is not valid (e.g., in a 4x3 matrix beyond '9')
												P1 = calculateLEDs(row, col);
										}
                    displaySegment(number); 
                    while(!(P2 & (0x40 >> col)));  // Wait for the button to be released
                }
            }
        }
        P1 = 0;  // Turn off all LEDs after button release
    }
}

void displaySegment(int number){
	// Segment codes for numbers 0 to 9 and dash '-' on a seven-segment display
	const char segmentCodes[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xBF};  // 0xBF for '-'

    P3 = segmentCodes[number];  // Send the segment code to P3 (seven segment display)
}

int calculateLEDs(int row, int col){
	//PIN 0, 1, 2, 3 shows the row and PIN 4, 5 and 6 shows column pressed. 
	return (1 << row) | (1 << (col + 4));  // Set bits for both row and column
}
