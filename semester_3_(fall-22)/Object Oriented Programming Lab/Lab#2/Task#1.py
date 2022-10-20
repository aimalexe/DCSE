'''
2.4.1 Activity 
Reuse Complex class given in section 2.3.2 (C++), section 2.3.5 (Java), and section 2.3.6 (Python) to
perform arithmetic with complex numbers. Note that addition and printing is already done in given
sections. Add the following public methods to perform complex subtraction and multiplication as well:
a) Input: Write class function input() to take complex number real and imaginary parts from user on
runtime. Note: input takes no arguments and returns nothing.
b) Subtract two Complex numbers: Write class function subCom() taking two complex objects c1 and c2.
Difference is computed as following: the real part of the right operand is subtracted from the real part of
the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of
the left operand. Note: return type of subCom is void.
c) Multiply two Complex numbers: Write class function mulCom() taking two complex objects c1 and
c2. Product is computed as following: Suppose you are trying to compute the product of two complex
numbers a + bi and c + di. The real part will be ac – bd, while the imaginary part will be ad+ bc. Note:
return type of subCom is void.
Demonstrate and test the modified class and its objects using test cases given in Section 2.5.
'''
class Complex:
    def __init__(self, a = 0, b = 0):
        self.real = a
        self.imaginary = b

    def takeInput(self):
        print("\n\tEnter Complex Number:")
        self.real = input("Enter real part: ")
        self.imaginary = input("Enter imaginary part: ")

    def addCom( self, c1, c2):
        self.real = c1.real + c2.real
        self.imaginary = c1.imaginary + c2.imaginary

    def subCom( self, c1, c2):
        self.real = c1.real - c2.real
        self.imaginary = c1.imaginary - c2.imaginary
        
    def mulCom( self, c1, c2):
        self.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary)
        self.imaginary = (c1.real * c2.imaginary) + (c2.real * c1.imaginary)
    def show(self):
        if (self.imaginary >= 0):
            print(self.real, " + ", self.imaginary, "i\n") 
        else:
            print(self.real, " - ", -self.imaginary, "i\n")

c1 = Complex(3, 5)
#c1.takeInput()
print("c1 = ", end="")
c1.show()
c2 = Complex(5 , 3)
#c1.takeInput()
print("c2 = ", end="")
c2.show()
result = Complex()
result.addCom(c1, c2)
print("The addition is:\t", end="")
result.show()
result.subCom(c1, c2)
print("The subtraction is:\t", end="")
result.show()
result.mulCom(c1, c2)
print("The product is:\t", end="")
result.show()