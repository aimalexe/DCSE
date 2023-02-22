//Aimal Khan.

#include <iostream>
using namespace std;

class Point{
    public:
        float x, y;
        Point():x(0), y(0) {}
        Point(float xx, float yy): x(xx), y(yy) {}
};

class Element{
    public:
        Element *next;
        virtual void print() const = 0;
};

class Line: public Element{
    private:
        Point p1, p2;
    public:
        Line(const Point &p, const Point &q, Element *ptr){
            p1 = p;
            p2 = q;
            next = ptr;
        }
        void print() const;
};

class Circle: public Element{
    private:
        Point centre;
        float radius;
    public:
        Circle(const Point &cen, float rad, Element *ptr){
            centre = cen;
            radius = rad;
            next = ptr;
        }
        void print()const;
};

class Triangle: public Element{
    private:
        Point p1, p2, p3;
    public:
        Triangle(const Point p, const Point q, const Point r, Element* ptr){
            p1 = p;
            p2 = q;
            p3 = r;
            next = ptr;
        }
        void print() const;
};

class BoldLine : public Line{
    private:
        float boldness;
    public:
        BoldLine(const Point &p, const Point &q, float wid, Element *ptr):Line(p, q, ptr){

            boldness = wid;
        }
        void print () const;
};

void pr(const Point &p, const char* str = " , "){
    cout<< "( "<<p.x<<", "<<p.y<<")"<<str;
}

void Line::print() const {
    cout << "Line: ";
    pr(p1); pr(p2, "\n");
}

void Circle::print() const{
    cout<<"Circle: ";
    pr(centre);
    cout<< radius << endl;
}
void Triangle::print() const{
    cout<<"Triangle: ";
    pr(p1); pr(p2); pr(p3, " \n");
}
void BoldLine::print () const{
    this->Line::print();
    cout<<"\bBoldness: "<<boldness<<endl;
}

int main(){

    Element *start = NULL, *p;
    start = new Line(Point(33,21), Point(11.34, 6.54), start);
    start = new Circle(Point(4,4), 2, start);
    start = new Triangle(Point(4.5,4), Point(3.44,9.7), Point(2, 15), start);
    start = new BoldLine(Point(4,4.3),Point(17, 33), 0.2, start);

    for(p = start; p != NULL; p = p->next)
        p->print();

    return 0;
    //Refactor and Debugged by: Aimal Khan
}
