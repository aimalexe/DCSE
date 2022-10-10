#include <iostream>
using namespace std;

void swap (int* , int*);

int main(){
	int num1=0, num2=0;
	cout<<"Enter first value: ";
	cin>>num1;
	cout<<"Enter second value: ";
	cin>>num2;
	
	swap (&num1, &num2);
	//after swaping
	cout << "\n\tValues after exchange are:\n";
	cout << "\nFirst Value is: "<<num1;
	cout << "\nSecond Value is: "<<num2;

	return 0;
}
void swap (int *x , int *y){
	int swp;
	swp = *x;
	*x = *y;
	*y = swp;
}