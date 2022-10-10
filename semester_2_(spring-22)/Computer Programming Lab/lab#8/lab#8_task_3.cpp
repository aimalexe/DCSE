#include <iostream>
using namespace std;

int main(){
	int num, i=0, *ptr;
	cout << "Enter a number: ";
	cin>>num;
	ptr = &num;
	//incrementig
	for ( ; i<5; i++)
		(*ptr)++;
	cout << "The value after incrementation is: "<<*ptr;

	return 0;
}
