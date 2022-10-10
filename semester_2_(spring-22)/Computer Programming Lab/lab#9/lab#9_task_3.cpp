
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main(){
	string myArr[2], *ptr;
	ptr = myArr;
	cout<<"Enter your name? ";
	cin>>*ptr;
	cout<<"Enter your Registration no.? ";
	cin>>*(ptr + 1);
	getch();
	system("cls");
	cout<<"\nYour Name Is: "<<*ptr;
	cout<<"\nYour Registration no. Is: "<<*(ptr+1) ;
		
	return 0;
}
