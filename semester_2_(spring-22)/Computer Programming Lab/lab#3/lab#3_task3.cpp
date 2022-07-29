//3.	Check the greater of two numbers using ternary operator?

#include<iostream>
using namespace std;

int main(){
	int num_1=0, num_2=0;
	cout<<"Enter a number: ";
	cin>>num_1;
	cout<<"Enter a number: ";
	cin>>num_2;
	  num_1>num_2?cout<<num_1<<" is greater than "<<num_2 :
	  num_2>num_1?cout<<num_2<<" is greater than "<<num_1 :
	  			  cout<<num_1<<" is equal to "<<num_2 ;
	return 0;
}
