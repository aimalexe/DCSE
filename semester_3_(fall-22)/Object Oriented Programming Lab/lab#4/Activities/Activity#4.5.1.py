import copy
class Employ: 
    def __init__(self, na = " ", de = " " , sa = 0.0, se = 0.0):
        self.name = na
        self.department = de
        self.salary = sa
        self.service = se

    def __del__(self):
        print("Objects Destroyed!")

    def setEmploy(self):
        self.name = input("Enter Employ's name:\t")
        self.department = input("Enter Employ's Department:\t")
        self.salary = input("Enter Employ's Salary:\t")
        self.service = input("Enter Employ's Service:\t")

    def showEmploy (self):
        print("\n\nEmploy Data")
        print("Name:\t", self.name)
        print("Department:\t", self.department)
        print("Salary:\t", self.salary)
        print("Service of years:\t", self.service)

e1 = Employ()
e1.setEmploy()
e1.showEmploy()

e2 =Employ()
e2 = copy.deepcopy(e1)
e2.showEmploy()