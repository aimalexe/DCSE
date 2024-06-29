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
sbit column4 = P1^7;

// Function prototypes
void delayMilliseconds(unsigned int ms);
void sendLcdCommand(unsigned char command);
void sendLcdData(unsigned char _data);
void initializeLcdDisplay(void);
char scanKeypad(void);
void calculatorOperation(void);
void displayString(char *string);
void displayFullExpression(char firstNumber, char _operator, char secondNumber, int result);

// Main function
int main() {
    initializeLcdDisplay();  // Initialize the LCD display
    while (1) {
        calculatorOperation();  // Perform calculator operations
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
    sendLcdCommand(0x0C);  // Display ON, cursor OFF
    sendLcdCommand(0x01);  // Clear display
    sendLcdCommand(0x06);  // Entry mode set
}

// Perform calculator operations
void calculatorOperation(void) {
    char key, firstNumber = 0, secondNumber = 0; 
		int result;
    char _operator = 0;

    sendLcdCommand(0x01);  // Clear display
    displayString("Enter 1st no."); // Display Enter first number
    
    // Wait for first number
    while(1) {
        key = scanKeypad();
        if (key >= '0' && key <= '9') {
            firstNumber = key - '0';
            sendLcdCommand(0xC0);  // next line
            sendLcdData(key);  // Show first number
						delayMilliseconds(1000);
            break;
        }
    }
		sendLcdCommand(0x01);  // Clear display
    displayString("Enter operator."); // Display Enter operaator
		
    // Wait for operator
    while(1) {
        key = scanKeypad();
        if (key == '+' || key == '-' || key == '*' || key == '/') {
            _operator = key;
						sendLcdCommand(0xC0);  // next line
            sendLcdData(key);  // Show operator
						delayMilliseconds(1000);
            break;
        }
    }
		
		sendLcdCommand(0x01);  // Clear display
    displayString("Enter 2nd no."); // Display Enter operaator
		
    // Wait for second number
    while(1) {
        key = scanKeypad();
        if (key >= '0' && key <= '9') {
            secondNumber = key - '0';
						sendLcdCommand(0xC0);  // next line
            sendLcdData(key);  // Show second number
						delayMilliseconds(1000);
            break;
        }
    }

    // Calculate result
    switch (_operator) {
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '*':
            result = firstNumber * secondNumber;
            break;
        case '/':
            if (secondNumber != 0)
                result = firstNumber / secondNumber;
            else
                result = 0;  // Handle division by zero
            break;
    }

    // Display result
		displayFullExpression(firstNumber, _operator, secondNumber, result);
}

// Read the key pressed on the keypad
char scanKeypad(void) {
    unsigned char keyMap[4][4] = {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'e', '=', '0', '+'}};
    unsigned char row, col;

    for (row = 0; row < 4; row++) {
        P1 = ~(1 << row);  // Ground one row at a time

        for (col = 0; col < 4; col++) {
            if (!(P1 & (1 << (col + 4)))) {  // Check if column is low
                delayMilliseconds(20);       // Debounce delay
                while (!(P1 & (1 << (col + 4))));  // Wait for key release
                return keyMap[row][col];    // Return the corresponding key
            }
        }
    }

    return ' '; 
}

// Function to display strings on the LCD
void displayString(char *string) {
    while (*string) {
        sendLcdData(*string++);
    }
}

void displayFullExpression(char firstNumber, char _operator, char secondNumber, int result) {
			char key;
	
		sendLcdCommand(0x01);  // Clear the LCD display
		
		sendLcdCommand(0x80);  // Position cursor at the beginning of the first line
		displayString("The Result is: "); 
		
		sendLcdCommand(0xC0);  // Position cursor at the beginning of the second line

    // Display the first number
    sendLcdData(firstNumber + '0');  // Convert number to ASCII

    // Display the operator
    sendLcdData(' ');  // Add space for clarity
    sendLcdData(_operator);
    sendLcdData(' ');  // Add space for clarity

    // Display the second number
    sendLcdData(secondNumber + '0');  // Convert number to ASCII

    // Display equals sign
    sendLcdData(' ');
    sendLcdData('=');
    sendLcdData(' ');

    // Display result
		sendLcdData(result + '0');
		
		while(1){
			key = scanKeypad();
			if(key == 'e')
				break;
		}
}
