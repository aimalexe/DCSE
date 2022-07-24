#include <iostream>
using namespace std;

int main(){
	int size=0, i=0, small=0, secSmall=0;
	//Takin size of the array
	cout << "How many elements are you entering: ";
	cin >> size; 
	if (size < 2)
		cout << "\nFor Comparison you must have to enter more than 2 elements.\n";
	else{
		// Declearing array of input size
		int inputArr[size];
		cout<< "\nEnter " << size <<" elements.\n";
		// taking data in array from user
		do{
			cout<<"Enter number in ["<<i<<"]: ";
			cin>>inputArr[i];
			i++;
		}while(i < size);
		//Calculating small and smaller number.
		small=secSmall=inputArr[0];
		for (i=0 ; i<size ; i++){
			if(inputArr[i]<small) {
				secSmall=small;
				small=inputArr[i];
			}
			else if(secSmall> inputArr[i] && inputArr[i] != small)
				secSmall= inputArr[i];
		}
		// Displaying the result. 
		cout<<"\nThe smallest number is: "<<small;
		cout<<"\nThe second smallest number is: "<<secSmall;
	}
	return 0;
}
