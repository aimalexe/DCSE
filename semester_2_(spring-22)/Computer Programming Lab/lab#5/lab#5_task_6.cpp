/*6.	Write a program to input array from user and display the elements of array in
		reverse order (use separate loops for input and output operation).
*/
#include <iostream>
using namespace std;

int main(){
	int size=5, i=0;
	cout << "Enter size for array: ";
	cin>>size;
	int inputArr[size];

	//taking input
	do{
		cout << "Enter element in inputArr ["<<i<<"] : ";
		cin >> inputArr[i];
		i++;
	}while(i < size);
	
	//displaying
	for (i=size-1; i >= 0; i--){
		cout<<"Element in inputArr ["<<i<<"] is: "<< inputArr[i]<<endl;
	}
	return 0;
}
