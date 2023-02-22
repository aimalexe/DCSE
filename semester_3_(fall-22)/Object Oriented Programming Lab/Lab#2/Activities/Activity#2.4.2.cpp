/*
2.4.2 Activity 
Reuse Complex class written in Activity 2.4.1 to modify the addCom(), subCom(), and mulCom() class
functions. Instead of passing two objects in each, now pass only one object. Change the return type of
each function to complex. Adjust the function code to match the changes. Demonstrate and test the
modified class and its objects using test cases given in Section 2.5.
*/

#include <iostream>
using namespace std;

class Complex {
	private:
		float real, imaginary;
	public:
		Complex ();
		void input();
		Complex addCom( Complex, Complex );
		Complex subCom( Complex, Complex );
		Complex mulCom( Complex, Complex );
		void show();
};

Complex::Complex():real(0), imaginary(0){}
void Complex::input(){
	cout << "\n\tEnter Complex Number:\nEnter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imaginary;
}
Complex Complex::addCom( Complex c1, Complex c2 ){
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.imaginary = c1.imaginary + c2.imaginary;
	return temp;
}
Complex Complex::subCom( Complex c1, Complex c2 ){
	Complex temp;
	temp.real = c1.real - c2.real;
	temp.imaginary = c1.imaginary - c2.imaginary;
	return temp;
}
Complex Complex::mulCom( Complex c1, Complex c2){
	Complex temp;
	temp.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
	temp.imaginary = (c1.real * c2.imaginary) + (c2.real * c1.imaginary);
	return temp;
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
	result = result.addCom(c1, c2);
	cout << "\nThe addition is:\t" ; result.show();
	result = result.subCom(c1, c2);
	cout << "The subtraction is:\t" ; result.show();
	result = result.mulCom(c1, c2);
	cout << "The product is:\t" ; result.show();
	return 0;
}
	