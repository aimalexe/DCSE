#include <iostream>
using namespace std;

void print (int);
int main(){
	print (10);
	return 0;
}

void print (int times){
	if (times==0)
		return;
	cout<<"\n\nAimal Khan.\n21PWCSE1996";
	print(times-1);
}


