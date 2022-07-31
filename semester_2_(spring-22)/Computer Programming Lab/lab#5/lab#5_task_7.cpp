/*7.	Write a program to input multiple values from user using array and then ask user
		to input a key number and then compare it with values entered by user (for array)
		and then display the index number of array with which value get matched (use separate
		loops for input operation and calculation) (use different loops for input operation and calculation).
*/
#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int size=5, num=0, i=0, index=-1;
	cout << "Enter size for array: ";
	cin>>size;
	int inputArr[size];
	
	//taking input
	for (i=0 ; i < size; i++){
		cout<<"Enter element in inputArr ["<<i<<"] is: ";
		cin>> inputArr[i];
	}
	
	cout<< "\nEnter a number: ";
	cin>>num;
	
	//searching for number
	i=0;
	while (i<size){
		if (num == inputArr[i]){
			index=i;
			break;
		} 
		i++;
	}
		
	
	//showing index
	if (index >= 0)
		cout << num <<" is found in inputArr at position ["<<index<<"].";
	else
		cout<<"Number is not found.";

	return 0;
}
