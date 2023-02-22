//4.3.3 Example: Overloaded Constructor and Default Copy Constructor.
#include <iostream>
using namespace std;

class Complex{
    private:
        float re, im ;
    public:
        Complex(): re(0.0), im(0.0) {}
        Complex(float r, float i): re(r), im(i) {}
        void show() const {
            cout<<"Complex Number:\t";
            im >= 0 ?
                cout<< re << " + " << im << "i\n" :
                cout<< re << " - " << - im << "i\n";
        }
};
int main(){
    Complex c1(34.76, -65.88);
    c1.show();

    Complex c2 = c1;
    c2.show();

    Complex c3(c1);
    c3.show();

    return 0;
}
