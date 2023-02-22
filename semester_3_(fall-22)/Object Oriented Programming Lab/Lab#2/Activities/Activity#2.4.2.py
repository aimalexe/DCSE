'''
2.4.2 Activity 
Reuse Complex class written in Activity 2.4.1 to modify the addCom(), subCom(), and mulCom() class
functions. Instead of passing two objects in each, now pass only one object. Change the return type of
each function to complex. Adjust the function code to match the changes. Demonstrate and test the
modified class and its objects using test cases given in Section 2.5.
'''
class Complex:
    def __init__(self, a = 0, b = 0):
        self.real = a
        self.imaginary = b

    def takeInput(self):
        print("\tEnter Complex Number:")
        self.real = input("Enter real part: ")
        self.imaginary = input("Enter imaginary part: ")

    def addCom( self, c1, c2):
        temp = Complex()
        temp.real = c1.real + c2.real
        temp.imaginary = c1.imaginary + c2.imaginary
        return temp;

    def subCom( self, c1, c2):
        temp = Complex()
        temp.real = c1.real - c2.real
        temp.imaginary = c1.imaginary - c2.imaginary
        return temp
        
    def mulCom(self, c1, c2):
        temp = Complex()
        temp.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary)
        temp.imaginary = (c1.real * c2.imaginary) + (c2.real * c1.imaginary)
        return temp
    def show(self):
        if (float(self.imaginary) >= 0):
            print(self.real, " + ", self.imaginary, "i\n") 
        else:
            print(self.real, " - ", -self.imaginary, "i\n")

c1 = Complex(3, 2.5)
#c1.takeInput()
print("c1 = ", end="")
c1.show()
c2 = Complex(5 , 3)
#c2.takeInput()
print("c2 = ", end="")
c2.show()
result = Complex()
result = result.addCom(c1, c2)
print("The addition is:\t", end="")
result.show()
result = result.subCom(c1, c2)
print("The subtraction is:\t", end="")
result.show()
result = result.mulCom(c1, c2)
print("The product is:\t", end="")
result.show()