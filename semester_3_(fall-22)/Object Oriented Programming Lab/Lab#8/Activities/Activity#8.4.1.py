"""
8.4.1 Activity
Create  a  class  called  Distance  containing  two  members  feet  and  inches.  This  class  represents
distance measured in feet and inches. For this class, provide the following functions:
a) A no‐argument constructor that initializes the data members to some fixed values.
b) A 2‐argument constructor to initialize the values of feet and inches to the values sent from
the calling function at the time of creation of an object of type Distance.
c) A showDistance() to show the distance in feet and inches.
d) Overloaded arithmetic operators
    a. operator+ to add two distances: Feet and inches of both objects should add in their
    corresponding members. 12 inches constitute one feet. Make sure that the result of
    addition doesn’t violate this rule.
    b. operator+= for addition of two distances.
i) Overloaded relational operators
    a. operator > should return a variable of type bool to indicate whether 1st distance is
    greater than 2nd or not.
    b. operator < should return a variable of type bool to indicate whether 1st distance is
    smaller than 2nd or not.
    c. operator >= should return a variable of type bool to indicate whether 1st distance is
    greater than or equal to 2nd or not.
    d. operator <=  should return a variable of type bool to indicate whether 1st distance is
    smaller than or equal to 2nd or not.
j) Overloaded equality operators
    a. operator==should return a variable of type bool to indicate whether 1st Distance is
    `
    equal to the  2nd distance or not.
    b. Operator!= should a true value if both the distances are not equal and return a false
    if both are equal.
k) Overloaded operators for pre‐ and post‐ increment. These increment operators should add
a 1 to the inches. Keep track that inch should not exceed 12.
l) Overload  operators  for  pre‐  and  post‐  decrement.  These  decrement  operators  should
subtract  a  1  from  inches.  If  number  of  inches  goes  below  0,  take  appropriate  actions  to
make this value valid.
"""

class Distance:
    def __init__(self, f = 0, i = 0):
        self.feet = f
        self.inches = i

    def show(self):
        print(f"{ self.feet }', { self.inches}''")
    
    def getInput(self):
        self.feet = input("Enter feet? ")
        self.inches = input("Enter inches? ")
        self.standardForm()

    def standardForm(self):
        while float(self.inches) >= 12: #for positive inches
            self.inches -= 12
            self.feet += 1

        while int(self.inches) < 0:  #for negative inches
            self.inches += 12
            self.feet -= 1
        
    def __add__(self, other): #Binary + overloading
        temp = Distance()
        temp.feet = self.feet + other.feet
        temp.inches = self.inches + other.inches
        return temp
    
    def __iadd__(self, other): #Complex assignment += overloading
        self.feet += other.feet
        self.inches += other.inches
    
    def __isub__(self, other): #Complex assignment -= overloading
        self.feet -= other.feet
        self.inches -= other.inches
    
    def __lt__(self, other): #Comparison operator < overloading
        distanceInFeet1 = self.feet + self.inches / 12
        distanceInFeet2 = other.feet + other.inches / 12
        return True if distanceInFeet1 < distanceInFeet2 else False 
    
    def __gt__(self, other): #Comparison operator > overloading
        distanceInFeet1 = self.feet + self.inches / 12
        distanceInFeet2 = other.feet + other.inches / 12
        return True if distanceInFeet1 > distanceInFeet2 else False 
    
    def __le__(self, other): #Comparison operator <= overloading
        distanceInInches1 = self.feet * 12 + self.inches
        distanceInInches2 = other.feet * 12 + other.inches
        return True if distanceInInches1 <= distanceInInches2 else False 
    
    def __ge__(self, other): #Comparison operator >= overloading
        distanceInInches1 = self.feet * 12 + self.inches
        distanceInInches2 = other.feet * 12 + other.inches
        return True if distanceInInches1 >= distanceInInches2 else False 
    
    def __eq__(self, other): #Comparison operator == overloading
        distanceInInches1 = self.feet * 12 + self.inches
        distanceInInches2 = other.feet * 12 + other.inches
        return True if distanceInInches1 == distanceInInches2 else False 
    
    def __ne__(self, other): #Comparison operator != overloading
        distanceInInches1 = self.feet * 12 + self.inches
        distanceInInches2 = other.feet * 12 + other.inches
        return True if distanceInInches1 != distanceInInches2 else False 

dist1 = Distance()
dist1.show()

dist2 = Distance( 5, 11)
dist3 = Distance(11, 6)

dist2.show()
dist3.show()

dist1 = dist2 + dist3
dist1.show()