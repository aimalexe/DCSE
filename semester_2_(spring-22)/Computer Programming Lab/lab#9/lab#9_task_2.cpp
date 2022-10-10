#include <iostream>
using namespace std;

int main(){
	int userArr[12], i=0, *ptr;
	ptr = userArr;
	//taking input
	while(i<12){
		cout<<"Enter a number: ";
		cin>>*(ptr + i);
		i++;
	}
	//displaying output 
	for (i=0; i < 12 ; i++ ){
		if (i % 3 == 0)
			cout<<endl;
		cout<<"\tValue "<<i+1<<" = "<<*(ptr + i);
	}
	return 0;
}
