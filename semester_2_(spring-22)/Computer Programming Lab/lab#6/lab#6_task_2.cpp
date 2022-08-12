//2.	Write a function minmax () that takes four integers as input and display the minimum and maximum number

#include <iostream>
using namespace std;

void minmax (int, int, int, int);
main(){
	int nums[4];
	for(int i=0; i<4 ; i++){
		cout<<"Enter number "<<i+1<<" ?: ";
		cin>>nums[i];
	}
	minmax(nums[0], nums[1], nums[2], nums[3]);
}

void minmax(int n1, int n2, int n3, int n4){
	int min, max;
	if (n1 < n2 && n1 < n3 && n1 < n4)
		min = n1;
	else if (n2 < n1 && n2 < n3 && n2 < n4)
		min = n2;
	else if (n3 < n1 && n3 < n2 && n3 < n4)
		min = n3;
	else
		min = n4;
	
	
	if (n1 > n2 && n1 > n3 && n1 > n4)
		max = n1;
	else if (n2 > n1 && n2 > n3 && n2 > n4)
		max = n2;
	else if (n3 > n1 && n3 > n2 && n3 > n4)
		max = n3;
	else 
		max = n4;
	
	cout<<"\nThe minimum number is: "<<min;
	cout<<"\nThe maximum number is: "<<max;
}
