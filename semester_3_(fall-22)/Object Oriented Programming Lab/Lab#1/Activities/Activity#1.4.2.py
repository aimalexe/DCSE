'''
Create a class called Point that has two data members: x and y coordinates of the point. Provide a non
argument and a 2 argument constructor. Provide separate get and set functions for the each of the data
members i.e. getX, getY, setX, setY. The getter functions should return the corresponding values to the
calling function. Provide a display method to display the point in (x, y) format. Make appropriate
functions const
'''
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
        print("(", self.getX(), " , ", self.getY(), ")")

p1 = Point()
print("Original p1:\t")
p1.show()
print("Updated p1:\t")
p1.setX(2)
p1.setY(3)
p1.show()

p2 = Point(5, 7)
print("Original p2:\t")
p2.show()
print("Updated p2:\t")
p2.setX(6);
p2.setY(3);
p2.show();