
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
class B{
    private:
        int w;
    public:
        B(): w(0) {}
        B(int ww): w(ww) {}
        void showB() const {
            cout<<"w: " << w << endl;
        }

};
//Multiple Inheritance
class C: public A, public B {
    private:
        int v;
    public:
        C(): B(), A(), v(0) {}
        C(int vv, int ww, int xx, int yy, int zz): v(vv), B(ww), A(xx, yy, zz) {}
        void showC() const {
            cout<<"v: " << v << endl; showB(); showA();
        }

};


int main(){
     cout<<"\nobjC ->\n";
    C objC(1,2,3,4, 5) ;

    objC.showC();

    return 0;
}
