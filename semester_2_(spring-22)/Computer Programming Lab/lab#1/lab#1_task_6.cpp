//6.	Write a program to calculate area of an ellipse having its axes (ask user to input values of major, minor)

#include <iostream>
using namespace std;

main(){
	float mj_axes , mn_axes;
	double area , pi= 3.1415926535 ;
	
	cout<<"Enter major axes: ";
	cin>>mj_axes;
	
	cout<<"Enter minor axes: ";
	cin>>mn_axes;
	
	area = pi * mj_axes * mn_axes ;
	
	cout<<"The area of elipse is\t"<<area<<"\tunit-square.\n\n";
}
