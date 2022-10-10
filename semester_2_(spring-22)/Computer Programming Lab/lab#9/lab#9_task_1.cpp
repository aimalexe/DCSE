#include <iostream>
using namespace std;

int main(){
	int arr[10], i, *ar;
	ar = arr;
	for (i =0 ; i<10; i++){
		cout<<"Enter a number ";
		cin>>*(ar + i);
	}
	i=0;
	while (i<10){
		cout<<*(ar + i)<<endl;
		i++;
	}
	return 0;
}
