"""
6.3.2 Activity [Multiple Inheritance] [write in C++ and Python]
Create a class base. It contains one protected data member ba and two public functions input_base()
and show_base(). Use input_base() to take ba from user on runtime while show_base() to display
content of ba.
Create another class exponent. It also contains one protected data member exp and two public
functions input_exp() and show_exp(). Use input_exp() to take exp from user on runtime while
show_exp() to display content of exp.
Next, create derived class power from base class and exponent class. This class contains one data
member po. It contains three public functions. A constructor to initialize po with 1, an input function
in1(), and show1() function. The in1() calls input_base() and input_exp() functions. The show1() calls
show_base() and show_exp() functions; computes power using ba and exp and store in po; and displays
computed power.
Write main function to test the functionality. Create an object of power. Call in1() and show1()functions
according to test case given in 6.4.
Note: Write code for C++ and Python for this activity. Java does not support multiple inheritance.
"""

class Base:
    def inputBase(self):
        self.ba = input("Enter base? ")
    def showBase(self):
        print("Base: ", self.ba)

class Exponent:
    def inputExponent(self):
        self.exp = input("Enter exponent? ")
    def showExponent(self):
        print("Exponent: " , self.exp)

class Power (Base, Exponent):
    def __init__(self):
        super()
        self.pwr = 1
    def inputPower(self):
        self.inputBase()
        self.inputExponent()
    def showPower(self):
        self.pwr = pow(self.ba, self.exp)
        self.showBase()
        print(" raise to the ")
        self.showExponent()
        print("\nis equal to: ", self.pow)

p1 = Power()
p1.inputPower()
p1.showPower()
#TODO Calculate Power
