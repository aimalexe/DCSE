//2.	Check whether a number is even or odd?

#include <iostream>
using namespace std;

int main(){
	int num_1=0, remainder=0;
	cout<<"Enter a number: ";
	cin>>num_1;
	remainder = num_1%2;
	 if(remainder == 0){
	 	cout<<num_1<<" is even";
	 }else if(remainder == 1){
	 	cout<<num_1<<" is odd";
	 }else{
	 	cout<<"Enter a valid number!";
	 }
	 cout<<endl;
	return 0;
}
