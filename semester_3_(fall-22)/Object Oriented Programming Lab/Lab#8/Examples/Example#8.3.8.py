class Complex:
    def __init__(self, r = 0,i = 0):
        self.real = r
        self.imaginary = i

    def sum(self, other):
        temp = Complex()
        temp.real = self.real + other.real
        temp.imaginary = self.imaginary + other.imaginary
        return temp

    def __add__(self, other):
        temp = Complex()
        temp.real = self.real + other.real
        temp.imaginary = self.imaginary + other.imaginary
        return temp

    def __invert__(self):
        temp = Complex()
        temp.real = -self.real
        temp.imaginary = -self.imaginary
        return temp

    def show(self):
        if self.imaginary > 0:
            print(f"{self.real } + {self.imaginary }i")
        else:
            print(f"{self.real } - {-self.imaginary }i")

print("c1:\t", end = "0")
c1=Complex(2,3.5)
c1.show()

print("c2:\t", end = "0")
c2=Complex(3.5,4)
c2.show()

print("Summing c1 & c2: \t", end = "0")
c3=Complex()
c3=c1.sum(c2)
c3.show()

print("Adding c1 & c2: \t", end = "0")
c3 = c1 + c2
c3.show()

print("Inverting c1: \t", end = "0")
c1 = ~c1
c1.show()


