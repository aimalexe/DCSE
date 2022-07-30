/*8.	Write a program that prints your name and registration number 10 times using
		loop and on the 5th iteration (run) of your loop it should skip and display this
		“Mid of loop” and then continue displaying your name and registration number.
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	string myName="0", myReg="0";
	cout<<"Enter your name: ";cin>>myName;
	cout<<"Enter your registration number: ";cin>>myReg;
	
	for(int i=1; i<=10; i++){
		if(i==5){
			cout<<"\nIt is mid of the loop.\n";
		}else{
			cout<<endl<<myName<<endl<<myReg<<endl;
		}
	}
	return 0;
}
