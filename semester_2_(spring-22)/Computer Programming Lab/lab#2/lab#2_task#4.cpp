/*4.	Write a C++ program to prompt the user to input 3 integer values and print these
		values in forward and reversed order. 
*/
#include <iostream>
using namespace std;

main(){
	int a, b, c;
	cout<<"\tEnter any three integer:\n";
	cout<<"Enter a: "; cin>> a ;
	cout<<"Enter b: "; cin>> b ;
	cout<<"Enter c: "; cin>> c ;
	cout<<"in forward order:\n"<<a<<","<<b<<","<<c<<"\n"
		<<"in reverse order:\n"<<c<<","<<b<<","<<a;
}
