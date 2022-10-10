#include <iostream>
using namespace std;

long sum(int);
int main(){
	int num=0;
	cout<<"Enter a number: ";
	cin>>num;
	//sum (num);
	cout<<"The sum of numbers upto "<<num<<" is: "<<sum(num); 
	return 0;
}
long sum(int n){
	if (n > 0)
		return n + sum (n - 1);
	else 
		return 0;
}
