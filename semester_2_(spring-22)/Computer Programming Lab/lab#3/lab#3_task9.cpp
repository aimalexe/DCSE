/*9.	Write a program to calculate and print the Electricity bill of a given customer.
		The customer id and unit consumed by the user should be taken from the keyboard and display
		the total amount to pay to the customer. The charges are as follow:
		Unit	Charge/unit
		Up to 199	@1.20
		200 and above but less than 400	@1.50
		400 and above but less than 600	@1.80
		600 and above	@2.00
		If bill exceeds Rs. 400 then a surcharge of 15% will be charged 
*/

#include <iostream>
using namespace std;

int main(){
	int customer_id=0;
	float units_consumed=0 ,
		  unit_charges=0 ,
		  charges=0,
		  surcharge=0 ,
		  net=0;
		  
	cout<<"Enter your Costumer Id: ";
	cin>>customer_id;
	
	if(customer_id == 1001){
		cout<<"\t->Access Granted!\nEnter units consumed: ";
		cin>>units_consumed;
			
			if(units_consumed>0 && units_consumed<200){
				unit_charges=1.20;
				charges= unit_charges*units_consumed;
					if(charges>400){
					surcharge= (charges*15)/100;
					}
				cout<<"\nCustomer ID no.: "<<customer_id<<endl;
				cout<<"Units consumed: "<<units_consumed<<endl;
				cout<<"Amount Charges @Rs."<<charges<<" per unit: "<<unit_charges<<endl;
				cout<<"Surcharge Amount: "<<surcharge<<endl;
				cout<<"Net Amount Paid by the Customer: "<<charges+surcharge<<endl;
			}
			else if(units_consumed>=200 && units_consumed<400){
				unit_charges=1.50;
				charges= unit_charges*units_consumed;
					if(charges>400){
					surcharge= (charges*15)/100;
					}
				cout<<"\nCustomer ID no.: "<<customer_id<<endl;
				cout<<"Units consumed: "<<units_consumed<<endl;
				cout<<"Amount Charges @Rs."<<charges<<" per unit: "<<unit_charges<<endl;
				cout<<"Surcharge Amount: "<<surcharge<<endl;
				cout<<"Net Amount Paid by the Customer: "<<charges+surcharge<<endl;
			}
			else if(units_consumed>=400 && units_consumed<600){
				unit_charges=1.80;
				charges= unit_charges*units_consumed;
					if(charges>400){
					surcharge= (charges*15)/100;
					}
				cout<<"\nCustomer ID no.: "<<customer_id<<endl;
				cout<<"Units consumed: "<<units_consumed<<endl;
				cout<<"Amount Charges @Rs."<<charges<<" per unit: "<<unit_charges<<endl;
				cout<<"Surcharge Amount: "<<surcharge<<endl;
				cout<<"Net Amount Paid by the Customer: "<<charges+surcharge<<endl;
			}
			else if(units_consumed>=600){
				unit_charges=2.00;
				charges= unit_charges*units_consumed;
					if(charges>400){
					surcharge= (charges*15)/100;
					}
				cout<<"\nCustomer ID no.: "<<customer_id<<endl;
				cout<<"Units consumed: "<<units_consumed<<endl;
				cout<<"Amount Charges @Rs."<<charges<<" per unit: "<<unit_charges<<endl;
				cout<<"Surcharge Amount: "<<surcharge<<endl;
				cout<<"Net Amount Paid by the Customer: "<<charges+surcharge<<endl;
			}
			else{
				cout<<"syntax error!";
			}
	}
	else{
		cout<<"->Access Denied! Try again.";
	}
	return 0;
}
