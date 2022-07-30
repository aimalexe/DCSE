/*1.	Write a program to create Simple Calculator using switch case (the calculator must have
		a loop that it could keep on running and ask the user again for input after showing
		output from the previous inputs).
*/
#include <iostream>
using namespace std;

int main(){
	float num1=0, num2=0;
	char oper=0, ask=0;
	do{
		cout<<"\n\nEnter a number: ";
		cin>>num1;
		cout<<"Enter an operator: ";
		cin>>oper;
		cout<<"Enter another number: ";
		cin>>num2;
			switch(oper){
				case '+':
					cout<<"The sum of "<<num1<<" and "<<num2<<" is "<<num1+num2<<endl;
					break;
				case '-':
					cout<<"The subtraction of "<<num2<<" from "<<num1<<" is "<<num1-num2<<endl;
					break;
				case '*':
					cout<<"The product of "<<num1<<" and "<<num2<<" is "<<num1*num2<<endl;
					break;
				case '/':
					cout<<"The division of "<<num1<<" by "<<num2<<" is "<<num1/num2<<endl;
					break;
				default:
					cout<<"Invalid Operator Entry!"<<endl;	
			}
			cout<<"\nTo calculate again enter \'A\'. To exit enter any key. ";
			cin>>ask;
	}while(ask=='a' || ask=='A');		
	cout<<"\nThank you for using our calculator.";
	return 0;
}
