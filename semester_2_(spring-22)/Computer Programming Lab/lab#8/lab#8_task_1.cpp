#include <iostream>
using namespace std;

int main(){
	int num1=0, num2=0, sum=0, *ptr;
	cout<<"Enter a number: ";
	cin>>num1;
	cout<<"Enter a number: ";
	cin>>num2;
	sum= num1+num2;
	ptr = &sum;
	cout<<"The sum is: "<<*ptr;
	
	return 0;
}