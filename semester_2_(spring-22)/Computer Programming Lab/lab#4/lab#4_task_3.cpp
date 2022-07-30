//3.	Write a program to find Factorial of a number.

#include <iostream>
using namespace std;

int main(){
	int num=0, i=0, factorial=1;
	cout<<"Enter a number: ";
	cin>>num;
	if(num>=0){
		for(i=1; i<=num; i++){
		factorial=factorial*i;
		}
		cout<<"The factorial of \'"<<num<<"\' is: \'"<<factorial<<"\'\n";
	}else{
		cout<<"The Factorial of negative numbers doesn't exists.";
	}
	return 0;
}
