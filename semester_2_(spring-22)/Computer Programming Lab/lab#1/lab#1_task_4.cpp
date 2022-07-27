//4.	Write a program to find the mod of (5%2=) and (6%2=)

#include <iostream>
using namespace std;

main(){
	int a , b , c;
	a=5;
	b=6;
	c=2;
	
	float mod_1,mod_2;
	mod_1 = a % c;
	mod_2 = b % c;
	
	cout<<"reminder of 5/2 is: "<<mod_1<<endl;
	cout<<"reminder of 6/2 is: "<<mod_2<<endl;
}
