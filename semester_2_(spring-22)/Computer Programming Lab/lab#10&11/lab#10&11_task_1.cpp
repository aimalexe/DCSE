#include <iostream>
using namespace std;

struct phone{
	char areaCode[3];
	int exchange;
	int number;
};
int main(){
	phone userInput, initialized={'0','4','2', 867, 4982};
	//Taking user number
	cout<<"Enter your area code number? ";
	cin>>userInput.areaCode;
	cout<<"Enter your exchange number? ";
	cin>>userInput.exchange;	
	cout<<"Enter your number? ";
	cin>>userInput.number;
	//displaying both numbers
	cout<<"\nMy number is:\t("<<initialized.areaCode<<") "<<initialized.exchange
		<<"-"<<initialized.number;
	cout<<"\nYour number is:\t("<<userInput.areaCode<<") "<<userInput.exchange
		<<"-"<<userInput.number;
	return 0;
}