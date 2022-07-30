/*9.	Write a program that performs a survey tally on beverages. The program should prompt
		for the next person until a sentinel value of –1 is entered to terminate the program.
		Each person participating in the survey should choose their favorite beverage from the
		following list: 
		1.	Coffee		2. Tea 		3. Coke		4. Orange Juice*/


#include<iostream>
using namespace std;
int main(){
	int choice=0;
	int coffee=0, tea=0, coke=0, juice=0;
	int total=0, persons=0;
	
	cout<<"\t\t\tBaverages Survey\n";
	cout<<"1.\tCoffee\n2.\tTea\n3.\tCoke\n4.\tOrangeJuice\n";
	do{
		cout<<"\nPlease input the favorite beverage of person #"<<persons+1
			<<":\nChoose 1, 2, 3, or 4 from the above menu or -1 to exit the program"<<persons<<": \n";
		cin>>choice;
		switch(choice){
			case 1:
				coffee++;
				total++;
				persons++;
				break;
			case 2:
				tea++;
				total++;
				persons++;
				break;
			case 3:
				coke++;
				total++;
				persons++;
				break;
			case 4:
				juice++;
				total++;
				persons++;
				break;
			case -1:
				goto print;		
		}
	}while(1);
	
  print:
	cout<<"\n\n\nTotal number of peoples surveyed is: "<<persons<<endl;
	cout<<"Beverages\t\t\tNumber of votes\n";
	cout<<"**************************************************\n";
	cout<<"Coffee\t\t\t\t"<<coffee<<endl;
	cout<<"Tea\t\t\t\t"<<tea<<endl;
	cout<<"Coke\t\t\t\t"<<coke<<endl;
	cout<<"OrangeJuice\t\t\t"<<juice<<endl;
	cout<<"**************************************************";
	return 0;
}
