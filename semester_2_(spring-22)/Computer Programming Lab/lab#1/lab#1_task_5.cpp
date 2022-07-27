//5.	Write a program to calculate area of a circle having its radius (ask user to input radius).

#include <iostream>
using namespace std;

main(){
	float radius ;
	double area , pi= 3.1415926535;
	
	cout<<"Enter radius: ";
	cin>>radius;
	
	area=pi*radius*radius;
		
	cout<<"The area of circle is\t"<<area<<"\tunit-square\n\n";
}
