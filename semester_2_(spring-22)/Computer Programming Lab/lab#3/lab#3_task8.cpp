//8.	Write a C++ program to enter month number between (1-12) and print number of days in month.

#include <iostream>
using namespace std;

int main(){
	int month=0;
	cout<<"Enter the month number: ";
	cin>>month;
		switch(month){
			case 1:
				cout<<"January has 31 days.";break;
			case 2:
				cout<<"Feburary has 28|29 days.";break;
			case 3:
				cout<<"March has 31 days.";break;
			case 4:
				cout<<"April has 30 days.";break;
			case 5:
				cout<<"May has 31 days.";break;
			case 6:
				cout<<"June has 30 days.";break;
			case 7:
				cout<<"July has 31 days.";break;
			case 8:
				cout<<"August has 31 days.";break;
			case 9:
				cout<<"September has 30 days.";break;
			case 10:
				cout<<"October has 31 days.";break;
			case 11:
				cout<<"November has 30 days.";break;
			case 12:
				cout<<"December has 31 days.";break;
			default:
				cout<<"Invalid Entery!";break;
		}
	return 0;
}
