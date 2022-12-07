/*
7.4.1 Activity
Define an abstract base class shape that includes protected data members for area and volume of a
shape,  public methods  for  computing  area  and  volume  of  a  shape (make  these  functions  virtual),
and a display function to display the information about an object. Make this class abstract by making
display function pure virtual.
Derive  a  concrete  class  point  from  the shape  class.  This  point  class  contains  two  protected  data
members  that  hold  the  position  of  point.  Provide  no‐argument  and  2‐argument  constructors.
Override the appropriate functions of base class.
Derive a class Circle publicly from the point class. This class has a protected data member of radius.
Provide a no‐argument constructor to initialize the fields to some fixed values. Provide a 3‐argument
constructor to initialize the data members of Circle class to the values sent  from outside. Override
the methods of base class as required.
Derive another class Cylinder from the Circle class. Provide a protected data member for height of
cylinder.  Provide  a  no‐argument  constructor  for  initializing  the  data  members  to  default  values.
Provide  a  4‐argument  constructor  to initialize  x‐ and y‐coordinates,  radius, and  height  of  cylinder.
Override the methods of base class.
Write a driver program to check the polymorphic behavior of this class.
*/

#include <iostream>
using namespace std;

class Shape{
    protected:
        float area;
        float volume;
    public:
        void calcArea(){ cout<<"Area:\t" << 0 << endl; }
        virtual void calcVolume(){ cout<<"Volume:\t" << 0 << endl; }
        virtual void display() = 0;
};

class Point: public Shape{
    protected:
        float x;
        float y;
    public:
        Point(): x(0), y(0) {}
        Point(float a, float b): x(a), y(b) {}
        void clacArea(){ cout<<"Area of Point:\t" << 0 << endl; }
        void clacVolume(){ cout<<"Volume of Point:\t" << 0 << endl; }
        void display (){ cout<< "(" << x <<" , "<< y << ")" <<endl; }
};
class Circle : public Point{
    protected:
        float radius;
    public:
        Circle(): radius(0), Point() {}
        Circle(float a, float b, float c): radius(c), Point(a, b) {}
        void clacArea(){ cout<<"Area of Circle:\t" << 2 * 3.14 * radius * radius << endl; }
        void clacVolume(){ cout<<"Volume of Point:\t" << ( 4 / 3 )*(3.1417 * radius * radius * radius) << endl; }
        void display (){ cout<< "Center:\t(" << x <<" , "<< y << ")\nRadius:\t"<<radius<<endl; }
};
class Cylinder:public Circle{
    protected:
        float height;
    public:
        Cylinder():height(0), Circle() {}
        Cylinder(float a, float b, float c, float d):height(d), Circle(a, b, c) {}
        void clacArea(){ cout<<"Area of Circle:\t" << 2 * 3.14 * radius * (radius + height) << endl; }
        void clacVolume(){ cout<<"Volume of Point:\t" << 2 * 3.1417 * radius * radius * height << endl; }
        void display (){ cout<< "Center:\t(" << x <<" , "<< y << ")\nRadius:\t"<<radius<<"\nHeight:\t"<<height<<endl; }
};

int main(){
    Shape *shp;
    Point pnt(1,3);
    Circle cir(1,5,3);
    Cylinder cyl(4, 5, 6, 7);
//    Shape sh;
//    sh.display();

    cout<<"\nPoint:\n";
    shp = &pnt;
    shp->calcArea();
    shp->calcVolume();
    shp -> display();

    cout<<"\nCircle:\n";
    shp = &cir;
    shp->calcArea();
    shp->calcVolume();
    shp->display();

    cout<<"\nCylinder:\n";
    shp = &cyl;
    shp->calcArea();
    shp->calcVolume();
    shp->display();

    return 0;
}
