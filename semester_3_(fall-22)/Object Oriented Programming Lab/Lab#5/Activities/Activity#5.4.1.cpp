/*
5.4.1 Activity
Reuse Point class of Lab 1 (Activity 1.4.2) as base class. Make the member data protected. Write all
class member functions outside Point class.
Derive a class Circle from this Point class that has an additional data member: radius of the circle. The
point from which this circle is derived represents the center of circle. Provide a no-argument
constructor to initialize the radius and center coordinates to 0. Provide a 2-argument constructor: one
argument to initialize the radius of circle and the other argument to initialize the center of circle
(provide an object of point class in the second argument). Provide a 3-argument constructor that
takes three floats to initialize the radius, x-, and y-coordinates of the circle. Provide setter and getter
functions for radius of the circle. Provide two functions to determine the radius and circumference of
the circle. Write all class member functions outside Circle class.
Also derive another class Cylinder from the Point class. This class contains an additional data member:
radius and height of cylinder. Provide appropriate constructors to initialize the center, radius, and
height of the cylinder. Provide functions to determine the area and volume of the cylinder. Area of a
cylinder is 2πr*(r + h). Volume of cylinder is 2πr*r*h. Use the findCircum() of circle class where
required. Write a main function to test these classes.
*/

#include <iostream>
using namespace std;

class Point{
     protected:
        float x, y;
     public:
         //constructors
         Point();
         Point(float a, float b);
        //setter and getter
        void setX(float a);
        void setY(float b);
        float getX();
        float getY();
        //displaying Point
         void show();
};
class Circle: public Point{
    private:
        float radius;
    public:
        Circle();
        Circle(float a, float b, float c);
        //setter and getter
        void setRadius(float a);
        float getRadius();
        void radiusLength();
        void circumference();
};
class Cylinder : public Point{
    protected:
        float radius;
        float height;
    public:
        Cylinder();
        Cylinder(float a, float b, float c, float d);
        void area();
        void volume();
};


//Defining Point Class Members
Point::Point(): x(0), y(0){}
Point::Point(float a, float b):x(a), y(b) {}
void Point::setX(float a){ x = a; }
void Point::setY(float b){ y = b; }
float Point::getX(){ return x; }
float Point::getY(){ return y; }
void Point::show(){
    cout<< "Point:\t(" << getX() << " , " << getY() << ")" <<endl;
}

//Defining Circle Class Members.
Circle::Circle(): Point(), radius(0) {}
Circle::Circle(float a, float b, float c): Point(a, b), radius(c) {}
void Circle::setRadius(float a){ radius = a; }
float Circle::getRadius(){ return radius; }
void Circle::radiusLength(){ cout<< "Radius of Circle:\t" << getRadius() <<endl; }
void Circle::circumference(){ cout<< "Circumference of Circle:\t" << 2 * 3.1417 * getRadius() <<endl; }

//Defining Cylinder Class Members.
Cylinder::Cylinder():Point(), radius(0), height(0) {}
Cylinder::Cylinder(float a, float b, float c, float d): Point(a, b), radius(c), height(d) {}
void Cylinder::area(){ cout<< "Area of Cylinder:\t" << 2*3.1417*radius*(radius + height) <<endl; }
void Cylinder::volume(){ cout<< "Volume of Cylinder:\t" << 2 * 3.1417 * radius * radius * height <<endl; }


int main(){
    Point p1(2, 3);
    p1.show();

    Circle cir(2, 3, 4);
    cir.radiusLength();
    cir.circumference();

    Cylinder cyl(2, 3, 4, 6.4);
    cyl.area();
    cyl.volume();
    return 0;
}
