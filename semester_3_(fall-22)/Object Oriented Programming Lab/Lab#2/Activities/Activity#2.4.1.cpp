/*
2.4.1 Activity 
Reuse Complex class given in section 2.3.2 (C++), section 2.3.5 (Java), and section 2.3.6 (Python) to
perform arithmetic with complex numbers. Note that addition and printing is already done in given
sections. Add the following public methods to perform complex subtraction and multiplication as well:
a) Input: Write class function input() to take complex number real and imaginary parts from user on
runtime. Note: input takes no arguments and returns nothing.
b) Subtract two Complex numbers: Write class function subCom() taking two complex objects c1 and c2.
Difference is computed as following: the real part of the right operand is subtracted from the real part of
the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of
the left operand. Note: return type of subCom is void.
c) Multiply two Complex numbers: Write class function mulCom() taking two complex objects c1 and
c2. Product is computed as following: Suppose you are trying to compute the product of two complex
numbers a + bi and c + di. The real part will be ac – bd, while the imaginary part will be ad+ bc. Note:
return type of subCom is void.
Demonstrate and test the modified class and its objects using test cases given in Section 2.5.
*/
#include <iostream>
using namespace std;

class Complex {
	private:
		float real, imaginary;
	public:
		Complex ();
		void input();
		void addCom( Complex, Complex );
		void subCom( Complex, Complex );
		void mulCom( Complex, Complex );
		void show();
};

Complex::Complex():real(0), imaginary(0){}
void Complex::input(){
	cout << "\n\tEnter Complex Number:\nEnter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imaginary;
}
void Complex::addCom( Complex c1, Complex c2 ){
	real = c1.real + c2.real;
	imaginary = c1.imaginary + c2.imaginary;
}
void Complex::subCom( Complex c1, Complex c2 ){
	real = c1.real - c2.real;
	imaginary = c1.imaginary - c2.imaginary;
}
void Complex::mulCom( Complex c1, Complex c2){
	real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
	imaginary = (c1.real * c2.imaginary) + (c2.real * c1.imaginary);
}
void Complex::show(){
	imaginary >= 0 ?
        cout<< real << " + " << imaginary << "i\n" :
        cout<< real << " - " << - imaginary << "i\n";
}

int main(){
	Complex c1 , c2, result;
	c1.input();
	cout << "c1 = ";c1.show();
	c2.input();
	cout << "c2 = ";c2.show();
	result.addCom(c1, c2);
	cout << "\nThe addition is:\t" ; result.show();
	result.subCom(c1, c2);
	cout << "The subtraction is:\t" ; result.show();
	result.mulCom(c1, c2);	
	cout << "The product is:\t" ; result.show();
	
	return 0;
}