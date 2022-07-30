//4.	Write a program to print multiplication table of any number.

#include <iostream>
using namespace std;

int main(){
	int num=0, i=0, times=0, prod=0;
	cout<<"Enter a number of which table do you want: ";
	cin>>num;
	cout<<"How many times do you want? ";
	cin>>times;
	for(i=0; i<=times; i++){
		prod=num*i;
		cout<<num<<" x "<<i<<" = "<<prod<<endl;
	}
	return 0;
}
