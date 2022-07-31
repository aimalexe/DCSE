/*2.	Write a program to input twelve numbers from user using array and display all
		values on console (3 values in a row) (use separate loops for input and output operation).
*/
#include <iostream>
using namespace std;

int main(){
	int arr[12], i=0;
	while(i<=11){
		cout << "Enter a number: ";
		cin>>arr[i];
		i++;
	}
	cout<<endl<<endl;
	for(int i=0; i<=11; i++){
		cout<<"\tValue "<<i+1<<"? ";
		cout<<arr[i];
		if ((i+1)%3 == 0)
			cout<<endl;
	}
	return 0;
}

