#include <iostream>
using namespace std;

class factorial{
	private:
		int num, fact=1;
	
	public:
		factorial(int n){
			num = n;
			for (int i =1 ; i <= num; i++)
				fact = fact * i;
		}
		void viewFact();
		~factorial(){
			cout<<"Thanks for Calculating!"<<endl;
		}
};
void factorial::viewFact(){
	cout<<num<<"! = "<<fact<<endl;
}
int main(){
	factorial n(10);
	n.viewFact();
	return 0;
}
