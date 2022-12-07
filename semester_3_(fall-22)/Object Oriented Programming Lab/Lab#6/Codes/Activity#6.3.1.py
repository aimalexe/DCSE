"""
6.3.1 Activity [Multilevel Inheritance] [write in all three languages]
Create a class First. It contains one protected data member f and one public input function f_input().
Use the function to take f from user on runtime.
Next, create a derived class Second from First class. This class also contains only one protected data
member s and one public input function s_input(). Call f_input() function inside s_input() and then take s
from user on runtime.
Finally, create another derived class Third from Second class. This class contains one protected data
member t. It contains three public functions. An input function t_input() that takes t from user on
runtime, a max function max() that finds maximum of f, s, and t and displays the maximum, and show
function that displays f, s, and t. Note, call s_input() inside t_input() and then take t from user.
Write main function to test the functionality. Create an object of Third. Call t_input(), show(), and max()
functions according to test case given in 6.4.
Note: For python, keep same name for input function i.e. in1() in all three classes.
"""

class First:
    def f_input(self):
        self.f = input("Enter f? ")

class Second(First):
    def s_input(self):
        self.f_input()
        self.s = input("Enter s? ")

class Third(Second):
    def t_input(self):
        self.s_input();
        self.t = input("Enter t? ")
    def maximum(self):
        print("\nThe maximum is: ", end="")
        if(self.f > self.s and self.f > self.t):
            print(self.f)
        elif(self.s > self.f and self.s > self.t):
            print(self.s)
        else :
            print(self.t)
    def show(self):
        print(f"\nfirst:\t{self.f}\nsecond:\t{self.s}\nthird:\t{self.t}")

obj = Third()
obj.t_input()
obj.show()
obj.maximum()