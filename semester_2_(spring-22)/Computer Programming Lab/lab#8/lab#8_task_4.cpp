#include <iostream>
#define line cout<<endl;
using namespace std;

int main(){
	string name, regno;
	string *ptr;
	
	//taking data
	cout<<"Enter your name: ";
	cin>>name;
	cout<<"Enter your registration no. : ";
	cin>>regno;
	
	//printing
	line
	ptr = &name;
	cout<<"Name: "<<*ptr;
	line
	ptr = &regno;
	cout<<"Registration no.: "<<*ptr;
	
	return 0;
}
