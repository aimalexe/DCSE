import copy

class Student: 
    def __init__(self, i=0, n="", g=0.0): 
        print("\tInitializing in Constructor") 
        self.id = i 
        self.name = n  
        self.gpa = g

    def __del__(self): 
        print("Freeing Memory!!")

    def show(self): 
        print(f"ID: {self.id}\nName: {self.name}\nGPA: {self.gpa}\n")

s1 = Student(1996, "Aimal Khan", 3.56) 
s1.show() 

print("\tShallow Copy")
s2 = copy.copy(s1)
s2.show()

print("\tDeep Copy")
s3 = copy.deepcopy(s1)
s3.show()

del s1 
del s2 
del s3