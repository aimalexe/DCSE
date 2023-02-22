class Polygon: 
    def __init__(self): 
        self.height = 0 
        self.length = 0

    def setValues(self, he, le): 
        self.height = he 
        self.length = le

class Rectangle(Polygon): 
    def area(self): 
        return self.height * self.length

class Triangle(Polygon): 
    def area(self): 
        return (self.height*self.length)/2 

rec = Rectangle() 
rec.setValues(13,21)
print("Area of Rectangle: ", rec.area()) 

tri = Triangle() 
tri.setValues(13,21) 
print("Area of Triangle: ", tri.area())