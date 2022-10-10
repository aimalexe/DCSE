#include <iostream>
using namespace std;

int fibonacci (int);

int main(){
	int num=0, i=0;
	cout <<"Enter the number of terms for fibonacci series: ";
	cin>>num;
	cout<<"\nThe Fibonacci Series is: "<<endl;
	
	while (i < num){
		cout<<" "<<fibonacci(i);
		i++;
	}
	return 0;
}

int fibonacci (int n){
	if (n==1 || n==0)
		return n;
	else
		return (fibonacci(n-1)+fibonacci(n-2));
}
