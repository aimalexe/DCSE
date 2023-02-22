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
class B:private A {
    private:
        int w;
    public:
        B(): A(), w(0) {}
        B(int ww, int xx, int yy, int zz): A(xx, yy, zz), w(ww) {}
        void showB() const {
            cout<<"w: " << w << endl; showA();
        }

};

//MultiLevel Inheritance
class C: public B {
    private:
        int v;
    public:
        C(): B(), v(0) {}
        C(int vv, int ww, int xx, int yy, int zz): B(ww, xx, yy, zz), v(vv) {}
        void showC() const {
            cout<<"v: " << v << endl; showB();
        }
};

int main(){
    A objA(2,3,4);
    cout<<"\nobjA ->\n";
    objA.showA();

    cout<<"\nobjB ->\n";
    B objB (11, 98, 67, 34);
    objB.showB();

     cout<<"\nobjC ->\n";
    C objC(1,2,3,4, 5) ;
    objC.showC();


    return 0;
}
