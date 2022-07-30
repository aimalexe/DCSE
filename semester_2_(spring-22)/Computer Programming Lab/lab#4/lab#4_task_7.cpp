//7.	Write a program that takes the base and exponent as input and display the result of power.

#include <iostream>
using namespace std;

int main(){
	float base=0, exponent=0, result=1;
	cout<<"Enter the base: ";
	cin>>base;
	cout<<"Enter the exponent/power: ";
	cin>>exponent;
		for(int i=1;i<=exponent; i++){
			result *= base;
		}
	cout<<base<<" to the power "<<exponent<<" is "<<result;
	return 0;
}
