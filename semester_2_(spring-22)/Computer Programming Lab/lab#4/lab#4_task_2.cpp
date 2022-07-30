/*2.	Write a program that takes a number as input, checks it if it is between 1 and 10
 		and if it is in valid range your program should output a line containing that number
		of adjacent asterisks. On invalid input number, the program should end
*/

#include <iostream>
using namespace std;

int main(){
	int num=0;
	cout<<"Enter a number between 1 and 10: ";
	cin>>num;
	if( num>1 && num<10){
		for(num; num>=1 && num<10; num--){
		cout<<"* ";	
		}	
	}else{
		cout<<"\nOoops! The number is not in range.";	
	}
	return 0;
}
