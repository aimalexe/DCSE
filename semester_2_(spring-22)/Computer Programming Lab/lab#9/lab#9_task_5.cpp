#include <iostream>
using namespace std;

void sum (int* , int*);

int main(){
	int arr [5], n1, n2, *pt;
	pt = arr;
	cout<<"Enter array:\n";
	for (int i =0 ; i < 5; i++){
		cout<<"Enter a number: ";
		cin >> *(pt + i);
	}
	cout<<"Entern value 1: ";
	cin>>n1;
	pt=&arr[n1];
	cout<<"Entern value 2: ";
	cin>>n2;
	pt=&arr[n2];
	
	sum (&n1, &n2);
	pt = arr;
	arr[0] = n1;
	cout<<"\n"<<arr[0];
	
}
void sum (int *num1, int *num2){
	*num1 += *num2;
}