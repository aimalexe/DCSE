/*
Create a class called Point that has two data members: x and y coordinates of the point. Provide a non
argument and a 2 argument constructor. Provide separate get and set functions for the each of the data
members i.e. getX, getY, setX, setY. The getter functions should return the corresponding values to the
calling function. Provide a display method to display the point in (x, y) format. Make appropriate
functions const
*/

#include <iostream>
using namespace std;

class Point{
     private:
        int x, y;
     public:
         //constructors
         Point(){
             x = 0;
             y = 0;
         }
         Point(int a, int b):x(a), y(b) {}
        //setter and getter
        void setX(int a){
            x = a;
        }
        void setY(int b){
            y = b;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        //display
         void show(){
            cout<< "(" << getX() << " , " << getY() << ")" <<endl;
         }
};

int main(){
    Point p1, p2(5,2);
    cout<< "Original p1:\t";
    p1.show();
    cout<< "Updated p1:\t";
    p1.setX(2);
    p1.setY(3);
    p1.show();

    cout<< "Original p2:\t";
    p2.show();
    cout<< "Updated p2:\t";
    p2.setX(6);
    p2.setY(3);
    p2.show();
    return 0;
}
