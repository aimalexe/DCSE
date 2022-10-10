#include <iostream>
#include <conio.h>
using namespace std;

struct movies{
	string title;
	int year;
};
int main(){
	movies m[3];
	//taking data;
	for (int i = 0; i<3; i++){
		cout<<"\nMovie name: ";
		cin>>m[i].title;
		cout<<"Releasing year? ";
		cin>>m[i].year;
	}
	getch();
	//displaying
	for (int i = 0; i<3; i++){
		cout<<"\n\nMovie name: "<<m[i].title;
		cout<<"\nReleasing year? "<<m[i].year;
	}
	return 0;
}
