#include <iostream>
using namespace std;

long fact (int);
int main(){
	int num=0;
	cout << "Enter a number : ";
	cin >> num;
	cout << "The factorial of "<<num<<" is "<<fact (num);

	return 0;
}
long fact (int n){
	if (n==1)
		return 1;
	else
		return n * fact (n - 1);
}

