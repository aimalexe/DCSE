#include <iostream>
using namespace std;

void grade (void);
float grade (int marks);
char grade (float percentage);

int main(){
	grade();
	return 0;
}
void grade (void){
	int mks;
	float g_prcnt;
	char g_grd;
	cout<<"Enter your marks: ";
	cin>>mks;
	g_prcnt = grade (mks);
	
	g_grd = grade (g_prcnt);
	
	cout<<"Your marks are: "<<mks;
	cout<<"\nYour %age is: "<<g_prcnt;
	cout<<"\nYour grade is: "<<g_grd;
}
float grade (int marks){
	float t_mks=150, prcnt=0;
	prcnt = (marks/t_mks)*100;
	return prcnt;
}
char grade (float percentage){
	char grd;
	if(percentage <= 100 && percentage >90)
		grd = 'A';
	else if(percentage <= 90 && percentage >80)
		grd = 'B';
	else if(percentage <= 80 && percentage >70)
		grd = 'C';
	else if(percentage <= 70 && percentage >60)
		grd = 'D';
	else if(percentage <= 60 && percentage >0)
		grd = 'F';
	else
		cout<<"Invalid value";
	return grd;
}
