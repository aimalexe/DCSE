//4.	Write a program to find a factorial of user input number. Use function to find factorial.

#include <iostream>
using namespace std;

int factorial (int);

main(){
	int num=0;
	cout << "Enter a number?: ";
	cin>>num;
	
	factorial(num);
	cout <<"The factorial of "<<num<<" is: "<<factorial(num);
}

int factorial (int n){
	int fact=1;
	for (int i=1 ; i<=n ; i++){
		fact=fact*i;
	}
	return fact;
}

