#include <iostream>
using namespace std;

float exponent (float, float);
int main(){
	float base=0, power=0; 
	cout << "Enter base : ";
	cin >> base;
	cout << "Enter power : ";
	cin>>power;
	cout<<base<<" raise to the power "<<power<<" is "<<exponent(base,power);

	return 0;
}
float exponent (float b, float e){
	if (e == 0)
		return 1;
	else
		return b * exponent (b, e-1);
}