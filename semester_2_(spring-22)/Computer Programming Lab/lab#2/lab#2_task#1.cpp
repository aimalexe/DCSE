//1.	Write a program that takes the temperature in Fahrenheit from the user and convert it to Celsius And Kelvin:

#include <iostream>
using namespace std;

main(){
	float f, c, k;
	
	cout<<"Enter temperature in Farenheit: ";
	cin>>f;
	
	c=(f-32)/1.8;
	cout<<"\nThe temperature in Celcius is: "<<c<<endl<<endl;
	
	k=c+273;
	cout<<"The temperature in Kelvin is: "<<k<<endl;
}
