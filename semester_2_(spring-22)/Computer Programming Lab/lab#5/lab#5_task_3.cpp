/*3.	Write a program to input ten numbers from user using array and find the
		average of numbers (use separate loops for input operation and calculation).
*/
#include <iostream>
using namespace std;

int main(){
	int i=0, sum=0, userArray[10];
	float  average=0;
	
	while(i<=9){
		cout << "Enter a number: ";
		cin>>userArray[i];
		i++;
	}
	for (i=0; i<=9; i++){
		sum=sum+userArray[i];
	}
	average = sum / 10;
	cout << "\nThe average value of this array is: "<<average;

	return 0;
}

