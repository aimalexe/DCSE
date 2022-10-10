#include <iostream>
using namespace std;

float addition (float, float);
float subtraction (float, float);
float multiplication (float, float);
float division (float, float);
float calculate(float, float, float (*p)(float, float));

int main(){
	float num1, num2;
	cout<<"Enter a value? ";cin>>num1 ;
	cout<<"Enter a value? ";cin>>num2 ;
	
	cout<<calculate(num1, num2, addition);
	return 0;
}
float addition (float n1, float n2){
	return n1 + n2;
}
float subtraction (float n1, float n2){
	return n1 - n2;
}
float multiplication (float n1, float n2){
	return n1 * n2;
}
float division (float n1, float n2){
	return n1 / n2;
}
float calculate(float n1, float n2, float(*p)(float, float)){
	return (*p)(n1, n2);
}