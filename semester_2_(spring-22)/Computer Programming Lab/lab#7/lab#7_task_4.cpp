#include <iostream>
using namespace std;

long oddSum(int);
int main(){
	int num=0;
	cout<<"Enter a number: ";
	cin>>num;
	//sum (num);
	cout<<"The sum of odd numbers upto "<<num<<" is: "<<oddSum(num); 
	return 0;
}
long oddSum(int n){
	if (n % 2 != 0){
		if (n > 0)
			return n + oddSum (n - 2);
		else 
			return 0;
	}
	else 
		return oddSum (n - 1);
}

