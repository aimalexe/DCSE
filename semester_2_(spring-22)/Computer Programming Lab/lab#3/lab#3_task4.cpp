/*4.	Write a program where you print you take a number from the user if the
		number is greater than 2 and then print your name and registration number 2
		times or else print only 1 time.
*/
#include<iostream>
using namespace std;

int main(){
	float num=0;
	cout<<"Enter a Number: ";
	cin>>num;
		if(num>2){
			cout<<"name: AIMAL KHAN.\nreg#: 21PWCSE1996.\n\n";
			cout<<"name: AIMAL KHAN.\nreg#: 21PWCSE1996.\n";
		}
		else{
			cout<<"name: AIMAL KHAN.\nreg#: 21PWCSE1996.\n";
		}
	return 0;
}
