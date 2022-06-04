#include <iostream>
using namespace std;

int main(){
	int inputI0=0, inputI1=5, inputI2=10, inputI3=15, inputI4=20,
		inputI5=25, inputI6=30, inputI7=35;
	int selectS1=0, selectS2=0, selectS3=0;
	
	cout<<"Select any selector with valid value only 1 or 0.\n\n";
	cout<<"Enter select line S1: ";cin>>selectS1;
	cout<<"Enter select line S2: ";cin>>selectS2;
	cout<<"Enter select line S3: ";cin>>selectS3;
	cout<<endl;
		if(selectS1==0 && selectS2==0 && selectS3==0){
			cout<<"The output is I0: "<<inputI0;
		}else if(selectS1==0 && selectS2==0 && selectS3==1){
			cout<<"The output is I1: "<<inputI1;
		}else if(selectS1==0 && selectS2==1 && selectS3==0){
			cout<<"The output is I2: "<<inputI2;
		}else if(selectS1==0 && selectS2==1 && selectS3==1){
			cout<<"The output is I3: "<<inputI3;
		}else if(selectS1==1 && selectS2==0 && selectS3==0){
			cout<<"The output is I4: "<<inputI4;
		}else if(selectS1==1 && selectS2==0 && selectS3==1){
			cout<<"The output is I5: "<<inputI5;
		}else if(selectS1==1 && selectS2==1 && selectS3==0){
			cout<<"The output is I6: "<<inputI6;
		}else if(selectS1==1 && selectS2==1 && selectS3==1){
			cout<<"The output is I7: "<<inputI7;
		}else{
			cout<<"Invalid Value of Selector Entered!";
		}
	return 0;
}
