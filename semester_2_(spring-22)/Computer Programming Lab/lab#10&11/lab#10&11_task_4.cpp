#include <iostream>
using namespace std;

struct students_t{
	string name;
	string regNo;
	int semester;
	float C_GPA;
};
int main(){
	students_t stds[3];
	string reg;
	int found=0, ind=0;
	//taking data;
	for(int i = 0; i<3; i++){
		cout<<"Name? "; cin>>stds[i].name;
		cout<<"Reg #? "; cin>>stds[i].regNo;
		cout<<"Semester? "; cin>>stds[i].semester;
		cout<<"C-GPA? "; cin>>stds[i].C_GPA;
	}
	//searching
	cout<<"Enter the reg no:- "; cin>>reg;
	for(int i=0; i<5; i++)
		if (reg == stds[i].regNo){
			found++;
			ind=i;
			break;
		}
	//Displaying
	if(found!=0){
		cout<<"\nName: "<<stds[ind].name;
		cout<<"\nReg #: "<<stds[ind].regNo;
		cout<<"\nSemester: "<<stds[ind].semester;
		cout<<"\nC-GPA: "<<stds[ind].C_GPA;
	}else
		cout<<"Record not found!";
	return 0;
}
