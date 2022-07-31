/*1.	Write a program in which you take your registration number and name as input into
		an array from the user and then output your registration number and name from the array.
		Use loops for input and output.
*/
#include <iostream>
using namespace std;

int main(){
	string myArray[2];
	int i=0;
	cout<<"Enter your Name and Registration no.:\n";
	while (i < 2){
		cin>>myArray[i];
		i++;		
	}
	cout<<endl;
	for (i=0; i<2 ; i++){
		cout<<myArray[i]<<endl;
	}
	return 0;
}

