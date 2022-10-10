#include <iostream>
using namespace std;

float average (int*, int);

int main(){
	int arr[5]={23, 45, 22, 87, 90}, *arrPtr;
	float aver;
	arrPtr = arr;
	aver = average(arrPtr, 5);
	cout<<"The average value is: "<<aver;
	return 0;
}
float average (int *arr, int size){
	int sum=0 ;
	float avrg;
	for (int i = 0; i<size; i++){
		sum += *(arr + i);
	}
	avrg = sum / size;
	return avrg;
}