/*6.3.1 Activity [Multilevel Inheritance] [write in all three languages]
Create a class First. It contains one protected data member f and one public input function f_input().
Use the function to take f from user on runtime.
Next, create a derived class Second from First class. This class also contains only one protected data
member s and one public input function s_input(). Call f_input() function inside s_input() and then take s
from user on runtime.
Finally, create another derived class Third from Second class. This class contains one protected data
member t. It contains three public functions. An input function t_input() that takes t from user on
runtime, a max function max() that finds maximum of f, s, and t and displays the maximum, and show
function that displays f, s, and t. Note, call s_input() inside t_input() and then take t from user.
Write main function to test the functionality. Create an object of Third. Call t_input(), show(), and max()
functions according to test case given in 6.4.
Note: For python, keep same name for input function i.e. in1() in all three classes.
*/
#include <iostream>
using namespace std;

class First{
    protected:
        int f;
    public:
        void f_input(){
            cout<<"Enter f? "; cin >> f;
        }
};
class Second : public First {
    protected:
        int s;
    public:
        void s_input(){
            f_input();
            cout<<"Enter s? "; cin >> s;
        }
};
class Third : public Second {
    protected:
        int t;
    public:
        void t_input(){
            s_input();
            cout<<"Enter t? "; cin >> t;
        }
        void maximum(){
            cout<<"\nThe maximum is: ";
            if(f > s && f > t) cout << f ;            else if(s > f && s > t) cout << s ;            else cout << t ;
            cout<<endl;
        }
        void show(){
            cout << "\nfirst:\t" << f <<"\nsecond:\t" << s << "\nthird:\t" << t << endl;
        }
};

int main (){
    Third obj;
    obj.t_input();
    obj.show();
    obj.maximum();
    return 0;
}
