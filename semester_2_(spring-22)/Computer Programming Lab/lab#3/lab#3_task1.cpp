//1.	Display the largest among three numbers using if else statement?

#include<iostream>
using namespace std;

int main(){
	float num_1=0, num_2=0, num_3=0;
	cout<<"Enter three unequal number.\n\n";
	cout<<"Enter a Number: ";
	cin>>num_1;
	cout<<"Enter another number: ";
	cin>>num_2;
	cout<<"Enter another number: ";
	cin>>num_3;
	if(num_1>num_2 && num_1>num_3){
		cout<<num_1<<" is greatest of these entered number.";	
	}else if(num_2>num_1 && num_2>num_3){
		cout<<num_2<<" is greatest of these entered number.";	
	}else if(num_3>num_1 && num_3>num_2){
		cout<<num_3<<" is greatest of these entered number.";	
	}else{
		cout<<"Invalid Entry!";
	}
	cout<<endl;
	return 0;
}
