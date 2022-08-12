/*5.	Write a program to find the roots of a quadratic equation of type a.x2+b.x+c where
		the value of a, b, c is to be entered by the user inside main() and the values must
		be stored inside an array called values. make sure value of a must be non-zero if it
		is complete the program. There must be two function one called roots() the other called
		deter(). First  main() will send the array values to deter to calculate d and then send
		the calculated d to roots() .
*/

#include <iostream>
#include <math.h>
using namespace std;

float deter (float, float, float);
void roots (float, float, float, float);

main(){
	float values[3], dis;
	
	cout<<"enter a? ";cin>>values[0];
	cout<<"enter b? ";cin>>values[1];
	cout<<"enter c? ";cin>>values[2];
	
	if (values[0]==0){
		cout<<"\'a\' cannot be zero.";
	}else{
		dis = deter(values[0], values[1], values[2]);
		cout<<endl;
		roots(values[0], values[1], values[2], dis);
	}
}

float deter (float a, float b, float c){
	int d;
	d= (b*b) - (4*a*c);
	return d;
}

void roots (float a, float b, float c, float d){
	float rt1,rt2;
	if(d>0){
		rt1= (-b + sqrt(d) ) / (2*a);
		rt2= (-b - sqrt(d) ) / (2*a);
		cout<<"The discriminent is greater than zero. Hence the roots are real and unequal.\n\n";
		cout<<"Root 1 is: "<<rt1<<"\nRoot 2 is: "<<rt2<<endl;		
	}else if(d==0){
		rt1 = rt2 = (-b) / (2*a);
		cout<<"The discriminent is equal to zero. Hence the roots are real and equal.\n\n";
		cout<<"Root 1 is: "<<rt1<<"\nRoot 2 is: "<<rt2<<endl;
	}else{
		rt1 = (-b) / (2*a);
		rt2 = (sqrt(d)) / (2*a);
		cout<<"The discriminent is less than zero. Hence the roots are imaginary and unequal.\n\n";
		cout<<"The real root is: "<<rt1<<"\n\nAnd imaginary roots are\n1: "<<rt2<<"\n2: "<<rt2<<endl;
	}
	
}

