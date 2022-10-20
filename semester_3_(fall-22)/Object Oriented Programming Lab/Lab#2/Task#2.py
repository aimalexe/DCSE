'''
2.4.2 Activity 
Reuse Complex class written in Activity 2.4.1 to modify the addCom(), subCom(), and mulCom() class
functions. Instead of passing two objects in each, now pass only one object. Change the return type of
each function to complex. Adjust the function code to match the changes. Demonstrate and test the
modified class and its objects using test cases given in Section 2.5.
'''
class Complex:
    def __init__(self, c1, c2):
        self.real = c1
        self.imaginary = c2