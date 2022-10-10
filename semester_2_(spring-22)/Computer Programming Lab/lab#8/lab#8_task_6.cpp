#include <iostream>
using namespace std;

int main(){
	int num=0, n=1, *ptr, sum=0;
	cout<<"Enter a number : ";
	cin >> num;
	if (num > 1){
		ptr = &n;
		for (*ptr = 1 ; *ptr <= num; ++(*ptr))
			if (*ptr % 2 == 0)
				sum += *ptr;
		cout << "\nThe sum of even numbers between 1 and "<<num<<" is: "<<sum;
	}else
		cout<<"Enter number greater than zero!";
	return 0;	
}
