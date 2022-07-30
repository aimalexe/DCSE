//6.	Write a program to print all-natural numbers in reverse (from n to 1).

#include <iostream>
using namespace std;

int main(){
	int num1=0;
	cout<<"Enter a number: ";
	cin>>num1;
	while(num1>=1){
		cout<<num1<<endl;
		num1--;
	}
	return 0;
}
