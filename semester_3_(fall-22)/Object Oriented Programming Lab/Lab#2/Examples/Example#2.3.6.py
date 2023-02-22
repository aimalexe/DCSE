class Complex:
    def __init__(self, r=0, i=0):
        self.real = r
        self.imaginary = i
    
    def addCom(self, c1, c2):
        self.real = c1.real + c2.real 
        self.imaginary = c1.imaginary + c2.imaginary 

    def negate(self):
        self.real = - self.real 
        self.imaginary = - self.imaginary 
        return self

    def show(self):
        if self.imaginary > 0:
            print(f"{self.real } + {self.imaginary }i")
        else:
            print(f"{self.real } - {-self.imaginary }i")

c1 = Complex(7, 8)
print("1st Complex Number: ", end = "0")
c1.show()

c2 = Complex(-5, -8)
print("2nd Complex Number: ", end = "0")
c2.show()

c3=Complex()
print("Sum of two Complex Number: ", end="0")
c3.addCom(c1,c2)
c3.show()

c4 = c1.negate()
print("Negation of  Complex Number: ",end="0")
c4.show()