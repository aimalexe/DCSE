#include <iostream>
using namespace std;

int sum (int = 75, int = 68);
int main(){
	int num1=0, num2=0;
	cout<<"Enter a number: ";
	cin>>num1;
	cout<<"Enter a number: ";
	cin>>num2;
	if (num1==0 || num2==0)
		cout<<"The sum of default values is: "<<sum();
	else
		cout<<"The sum is: "<<sum(num1, num2);

	return 0;
}
int sum (int x, int y){
	int s ;
	s = x + y;
	return s;
}