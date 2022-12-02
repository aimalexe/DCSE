
#include <iostream>
using namespace std;

class A{
    private:
        int x;
    protected:
        int y;
    public:
        int z;
        A():x(0), y(0), z(0) {}
        A(int xx, int yy, int zz):x(xx), y(yy), z(zz) {}
        void showA()const {
            cout<<"x: "<<x<<"\ny: "<<y<<"\nz: "<<z<<endl<<endl;
        }

};
//class childClassName:typeOfInheritance parentClassName {};
class B: public A{
    private:
        int w;
    public:
        B(): w(0), A() {}
        B(int ww, int xx, int yy, int zz): w(ww), A(xx, yy, zz) {}
        void showB() const {
            cout<<"w: " << w << endl; showA();
        }

};
//Multiple Inheritance
class C: public A {
    private:
        int w;
    public:
        C(): w(0), A() {}
        C(int ww, int xx, int yy, int zz): w(ww), A(xx, yy, zz) {}
        void showC() const {
            cout<<"w: " << w << endl; showA();
        }

};
int main(){
    cout<<"\nobjB ->\n";
    B objB(5,6,7,8) ;

    objB.showB();
     cout<<"\nobjC ->\n";
    C objC(1,2,3,4) ;

    objC.showC();

    return 0;
}
