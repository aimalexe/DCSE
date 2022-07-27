//5.	Write a program to swap two variables values with and without using third variables.

#include <iostream>
using namespace std;

main(){
	//swaping with using third variable:-
	int num1=0, num2=0, num3=0;
	cout<<"Enter a Number-1: ";
	cin>>num1;
	cout<<"Enter a Number-2: ";
	cin>>num2;
	cout<<"\n\tBefore swapping:\nNumber-1 = \'"<<num1<<"\' and Number-2 = \'"<<num2<<"\' \n";
		num3 = num1;
		num1 = num2;
		num2 = num3;
	cout<<"\n\tAfter swapping:\nNumber-1 = \'"<<num1<<"\' and Number-2 = \'"<<num2<<"\' \n";
}
