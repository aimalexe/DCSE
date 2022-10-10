#include <iostream>
using namespace std;

int main(){
	int num=0, n=1, *ptr;
	cout<<"Enter a number : ";
	cin >> num;
	ptr = &n;
	for (*ptr = 1 ; *ptr <= num; ++(*ptr))
		cout<<*ptr<<"  ";

	return 0;
}
