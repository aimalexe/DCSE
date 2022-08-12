/*3.	Your program should have a function named ‘prime’ which accepts an integer and return
		a Boolean (a true if the number is prime and false otherwise). Return type bool function
*/
#include <iostream>
using namespace std;

bool prime (int);

main(){
	int num=0;
	cout << "Enter a number ?: ";
	cin>>num;
	
	prime (num);
	
	if (prime(num))
		cout<<"The "<<num<<" is a prime number.";
	else
		cout<<"The "<<num<<" is a composite number.";
}

bool prime (int n){
	bool p;
	for (int i=2; i<=n/2; i++){
		if (n % i != 0)
			p=true;
		else{
			p=false;
			break;	
		}	
	}
	return p;
}
