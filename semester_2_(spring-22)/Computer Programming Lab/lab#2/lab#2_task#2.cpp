/*2.	Write the C++ code that takes the integer a, b, c, d and e from the user and display the output
		according to the following equation.

	               a3 + b – d / b                                  
	 a (b + c (e + a) / b) - 5
*/


#include <iostream>
using namespace std;

main(){
	int a=0, b=0, c=0, d=0, e=0;
	float f=0, numerator=0, denomenator=0, answer=0;
	
	cout<<"Enter 'a': " ; cin>> a ;
	cout<<"Enter 'b': " ; cin>> b ;
	cout<<"Enter 'c': " ; cin>> c ;
	cout<<"Enter 'd': " ; cin>> d ;
	cout<<"Enter 'e': " ; cin>> e ;
		numerator = (a*a*a + b - d )/b;
		denomenator = ((a*(b + c*(e + a))) / b) - 5;
		answer = numerator / denomenator ; 
	//f=((a*a*a + b - d )/b) / (a*(b + c*(e + a) / b) - 5 );
	cout<<"\nThe output is: "<<answer;
}
