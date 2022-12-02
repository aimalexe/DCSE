"""
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
"""

class Point:
    def __init__(self, a = 0, b = 0):
        self.x = a
        self.y = b

    def getX(self):
        return self.x
    
    def setX(self, a):
        self.x = a

    def getY(self):
        return self.y
    
    def setY(self, a):
        self.y = a

    def show(self):
        print("Point:\t(", self.getX(), " , ", self.getY(), ")")


class Circle(Point):
    def __init__(self, a=0, b=0, c=0):
        super().__init__(a, b)
        self.radius = c

    def setRadius (self, r):
        self.radius = r

    def getRadius (self):
        return self.radius

    def radiusLength (self):
        print("Radius of Circle:\t", self.getRadius())

    def circumference(self):
        print("Circumference of Circle:\t", 2 * 3.1417 * self.radius)

class Cylinder ( Point ):
    def __init__(self, a=0, b=0, c=0, d=0 ):
        super().__init__(a, b)
        self.radius = c
        self.height = d

    def area(self):
        print("Area of Cylinder:\t", 2 * 3.1417 * self.radius * (self.radius + self.height) )

    def volume(self):
        print("Volume of Cylinder:\t",2 * 3.1417 * self.radius * self.radius * self.height )

p1 = Point(2, 3)
p1.show()

cir = Circle(2, 3, 4)
cir.radiusLength()
cir.circumference()

cyl = Cylinder(2, 3, 4, 6.4)
cyl.area()
cyl.volume()
