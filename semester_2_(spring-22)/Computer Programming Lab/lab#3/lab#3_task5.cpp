/*5.	Write a program that asks a number and test the number whether it is multiple of 5 or
		not, divisible by 7 but not by eleven. (all three conditions should match)
*/
#include <iostream>
using namespace std;

int main(){
	int num=0, mult5=0, div7=0, div11=0;
	cout<<"Enter a number: ";
	cin>>num;
	 mult5= num%5;
	 div7 = num%7;
	 div11 = num%11;
		if(mult5==0 && div7==0 && div11!=0){
			cout<<"The number is multiple of 5, divisible by 7 but not by 11.";
		}
		else{
			cout<<"The condition fails.";
		}
	return 0;
}
