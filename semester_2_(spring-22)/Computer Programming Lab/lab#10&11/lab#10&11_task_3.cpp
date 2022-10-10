#include <iostream>
using namespace std;

struct point{
	int x_cord;
	int y_cord;
};

int main(){
	point p1={4, 5};
	//taking data
	cout<<"Enter width? ";
	cin>>p1.x_cord;
	cout<<"Enter height? ";
	cin>>p1.y_cord;
	//generating the rectangle
	for(int rows=0 ;rows < p1.x_cord; rows++){
		for(int column=0 ;column < p1.y_cord; column++ )
			cout<<" *";
		cout<<endl;
	}
	return 0;
}
