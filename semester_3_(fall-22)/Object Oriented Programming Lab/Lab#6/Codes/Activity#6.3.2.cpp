/*6.3.2 Activity [Multiple Inheritance] [write in C++ and Python]
Create a class base. It contains one protected data member ba and two public functions input_base()
and show_base(). Use input_base() to take ba from user on runtime while show_base() to display
content of ba.
Create another class exponent. It also contains one protected data member exp and two public
functions input_exp() and show_exp(). Use input_exp() to take exp from user on runtime while
show_exp() to display content of exp.
Next, create derived class power from base class and exponent class. This class contains one data
member po. It contains three public functions. A constructor to initialize po with 1, an input function
in1(), and show1() function. The in1() calls input_base() and input_exp() functions. The show1() calls
show_base() and show_exp() functions; computes power using ba and exp and store in po; and displays
computed power.
Write main function to test the functionality. Create an object of power. Call in1() and show1()functions
according to test case given in 6.4.
Note: Write code for C++ and Python for this activity. Java does not support multiple inheritance.
*/
#include <iostream>
using namespace std;

class Base{
    protected:
        float ba;
    public:
        void inputBase(){
            cout << "Enter base? "; cin >> ba;
        }
        void showBase(){
            cout << "Base: " << ba ;
        }
};
class Exponent{
    protected:
        float exp;
    public:
        void inputExponent(){
            cout << "Enter exponent? "; cin >> exp;
        }
        void showExponent(){
            cout << "Exponent: " << exp;
        }
};
class Power : public Base, public Exponent {
    protected:
        float pow;
    public:
        Power(): pow(1) {}
        void inputPower(){
            inputBase();
            inputExponent();
        }
        void showPower(){
            for(int i = 1; i <= exp ; i++ ){
                pow *= ba;
            }
            showBase();
            cout<<" raise to the ";
            showExponent();
            cout << "\nis equal to: " << pow;
        }
};
int main (){
    Power p1;
    p1.inputPower();
    p1.showPower();
    return 0;
}
