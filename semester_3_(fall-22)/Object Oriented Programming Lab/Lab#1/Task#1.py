'''
Create a class, Heater that contains a single integer field, temperature. Define a constructor that takes
no parameters. The temperature field should be set to the value 15 in the constructor. Define the
mutators: warmer and cooler, whose effect is to increase or decrease the value of the temperature by 5
respectively. Define an accessor method to return the value of temperature. Demonstrate the use of
Heater class.
'''
from email import header


class Heater:
    def __init__(self):
        self.temperature = 15
    
    def warmer(self):
        self.temperature += 5

    def cooler(self):
        self.temperature -= 5

    def getTemperature(self):
        return self.temperature

    def show(self):
        temp = self.getTemperature()
        print("Temperature: ", temp)

print("\nDemonstrating Heater-1:")
h1 = Heater()
h1.show()
h1.warmer()
h1.show()
h1.cooler()
h1.show()

print("\nDemonstrating Heater-1:")
h2 = Heater()
h2.show()
h2.cooler()
h2.show()
h2.warmer()
h2.show()





