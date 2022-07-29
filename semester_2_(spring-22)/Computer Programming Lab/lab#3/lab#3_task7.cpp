/*7.	Write a program that takes the weekday number as input from user and print the day name of week
		E.g., Print Monday if weekday number is equal to 1. Similarly, check condition for all 7 days
		and print the corresponding day name. Print an error message if an invalid number is entered.
*/

#include <iostream>ss
using namespace std;

int main(){
	int day=0;
	cout<<"Enter the weekday number: ";
	cin>>day;
		switch(day){
			case 1:
				cout<<"Monday";break;
			case 2:
				cout<<"Tuesday";break;
			case 3:
				cout<<"Wednesday";break;
			case 4:
				cout<<"Thursday";break;
			case 5:
				cout<<"Friday";break;		
			case 6:
				cout<<"Saturday";break;
			case 7:
				cout<<"Sunday";break;
			default:
				cout<<"Invalid Entery!";break;
		}
	return 0;
}
