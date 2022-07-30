/*5.	Write a program to input two integer numbers and display the sum of even
		numbers between these two input numbers.
*/
#include <iostream>
using namespace std;

int main(){
	int num_min=0, num_max=0, sum=0;
	cout<< "Enter the minimum number: " ;
	cin>> num_min;
	cout<< "Enter the maximum number: ";
	cin>> num_max;
		for(num_min; num_min<=num_max; num_min++){
			if(num_min%2==0){
				cout<< num_min << " " ;
				sum= sum + num_min ;
			}
		}
		cout<<"\n\nThe sum of all even numbers between the entered interval is: "
			<< sum << endl ;	
	return 0;
}
