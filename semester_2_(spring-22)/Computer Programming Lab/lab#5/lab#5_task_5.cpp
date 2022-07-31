//5.	Write a program to input two arrays from user and find the sum of arrays (element by element).

#include <iostream>
using namespace std;

int main(){
	int size=5, i=0;
	cout << "Enter size for array: ";
	cin>>size;
	int inputArr1[size], inputArr2[size], sum[size];

	//taking input
	do{
		cout << "Enter element in inputArr1 ["<<i<<"] : ";
		cin >> inputArr1[i];
		i++;
	}while(i < size);
	i=0;
	cout<<endl;
	do{
		cout << "Enter element in inputArr2 ["<<i<<"] : ";
		cin >> inputArr2 [i];
		i++;
	}while(i < size);
	
	///summing up
	for (i=0; i < size; i++){
		sum [i]=inputArr1 [i]+inputArr2 [i];
	}
	cout<<endl;
	//displaying
	for (i=0; i < size; i++){
		cout<<"The sum of both arrays (element by element) is: "<< sum [i]<<endl;
	}
	return 0;
}
