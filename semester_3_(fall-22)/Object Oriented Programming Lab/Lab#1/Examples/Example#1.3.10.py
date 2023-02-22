class Complex:
    def __init__(self, r = 0, i = 0):
        self.real = r
        self.imaginary = i

    def setValue(self, r, i):
        self.real = r
        self.imaginary = i

    def show(self):
        print(f"Complex number :{self.real} + {self.imaginary} i")

obj1 = Complex(11, 33)
obj1.show()

obj2 = Complex(-5,10)
obj2.show()
obj2.setValue(12,9)
obj2.show()