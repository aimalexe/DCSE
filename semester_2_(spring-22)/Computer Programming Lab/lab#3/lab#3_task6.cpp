//6.	Check whether the entered character is vowel or consonant?

#include <iostream>
using namespace std;

int main(){
	char ch='0';
	cout<<"enter a character: ";
	cin>>ch;
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
		   ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
			cout<<"The entered character is VOVEL.";
		}
		else{
			cout<<"The entered character is CONSONENT.";
		}
	return 0;
}
