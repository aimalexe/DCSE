import copy

class Students:
    def __init__ (self, na= " ", ag = 0, gp = 0.00):
        self.name = na
        self.age = ag
        self.gpa = gp

    def __del__ (self):
        print("Destructor in py")

    def show(self):
        print("Name: ", self.name)
        print("Age: ", self.age)
        print("GPA: ", self.gpa)

s1 = Students("Aimal Khan", 21, 3.56)
s1.show()

s2 = Students
s2 = copy.copy(s1)
s2.show()

s3 =Students
s3 = copy.deepcopy(s2)
s3.show()