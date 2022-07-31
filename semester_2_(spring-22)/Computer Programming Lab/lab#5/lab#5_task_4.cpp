/*4.	Write a program to input multiple values from user using array and find the
		maximum (use separate loops for input operation and calculation).
*/
#include <iostream>
using namespace std;

int main(){
	int i=0, arrSize=0;
	cout<<"How many numbers are you entering? ";
	cin >> arrSize;
	int arr[arrSize]={};
	do{
		cout<<"Enter a number: ";
		cin>>arr [i];
		i++;
	}while(i<arrSize);
	
	int max = arr[0];
	for (i=0; i<arrSize; i++){
		if (arr[i]>max)
			max=arr[i];
	}
	cout<<"\nThe maximum value is : "<<max;
	return 0;
}

