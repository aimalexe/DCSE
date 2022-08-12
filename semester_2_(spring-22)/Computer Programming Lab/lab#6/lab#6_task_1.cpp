/*1.	Write a program that takes marks and registration number as input and then displays
		your name, grade and registration number using function. (You must use your own name
		and registration number also the grade must be calculated on the bases of marks).
*/

#include <iostream>
#include <conio.h>
using namespace std;

string g (int);

main(){
	string r;
	int m = 0;
	
	cout<<"Enter your registration # ? ";
	cin>>r;
	cout<<"Enter your marks? ";
	cin>>m;
	if (r == "21pwcse1996" || r=="21PWCSE1996"){
		cout<<"\nName: Aimal Khan\n";
		cout<<"Reg# "<< r <<endl;
		cout<<"Grade: "<< g(m) <<endl;
	}else{
		cout<<"invalid regno.";
	}	
}

string g (int s){
	string gr;
	if (s>90 && s<=100){
		gr="A+";
	}else if (s>80 && s<=90){
		gr="A";
	}else if (s>70 && s<=80){
		gr="B+";
	}else if (s>60 && s<=70){
		gr="B";
	}else if (s>50 && s<=60){
		gr="C+";
	}else if (s>40 && s<=50){
		gr="C";
	}else if (s>0 && s<=40){
		gr="F";
	}else{
		gr="Invalid Marks Entery!";
	}

	return gr;
}

