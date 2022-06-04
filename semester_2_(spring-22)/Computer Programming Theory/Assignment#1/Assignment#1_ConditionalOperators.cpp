#include <iostream>
using namespace std;

int main(){
	int inputI0=0, inputI1=5, inputI2=10, inputI3=15, inputI4=20,
		inputI5=25, inputI6=30, inputI7=35 ;
	int selectS1=0, selectS2=0, selectS3=0 ;
	cout<<"\tSelect any selector with valid value only 1 or 0.\n";
	cout<<"Enter select line S1: ";cin>>selectS1;
	cout<<"Enter select line S2: ";cin>>selectS2;
	cout<<"Enter select line S3: ";cin>>selectS3;
	cout<<endl; 
		selectS1==0 ?
			(selectS2==0 ?
				(selectS3==0 ? cout<<"The output is I0: "<<inputI0 : 
					(selectS3==1? cout<<"The output is I1: "<<inputI1 : cout<<"Invalid Value of Selector Entered!")):
			 selectS2==1?
			 	(selectS3==0 ? cout<<"The output is I2: "<<inputI2 : 
				 	(selectS3==1 ? cout<<"The output is I3: "<<inputI3 : cout<<"Invalid Value of Selector Entered!")):
			 cout<<"Invalid Value of Selector Entered!"):
	
			 (selectS1==1 ?
			 	(selectS2==0 ?
					(selectS3==0 ? cout<<"The output is I4: "<<inputI4 : 
						(selectS3==1 ? cout<<"The output is I5: "<<inputI5 : cout<<"Invalid Value of Selector Entered!")):
			 	selectS2==1 ?
					(selectS3==0 ? cout<<"The output is I6: "<<inputI6 : 
						(selectS3==1 ? cout<<"the out put is I7: "<<inputI7 : cout<<"Invalid Value of Selector Entered!")):
			 	cout<<"Invalid Value of Selector Entered!"):
			 cout<<"Invalid Value of Selector Entered!");
	return 0;
	//Aimal Khan.
}
