/*
Create a class, Heater that contains a single integer field, temperature. Define a constructor that takes
no parameters. The temperature field should be set to the value 15 in the constructor. Define the
mutators: warmer and cooler, whose effect is to increase or decrease the value of the temperature by 5
respectively. Define an accessor method to return the value of temperature. Demonstrate the use of
Heater class.
*/
#include <iostream>
using namespace std;

class Heater {
    private:
        int temperature;

    public:
        //constructor to initialize 5.
        Heater():temperature(15){}
        //get current value of temperature.
        int getTemperature(){
            return temperature;
        }
        //Warming up or cooling down the temperature.
        void warmer(){
            temperature += 5;
        }
        void cooler(){
            temperature -= 5;
        }
        //displaing value.
        void show(){
            int currentTemperature = getTemperature();
            cout<<"Temperature: "<<currentTemperature<<endl;
        }
};

int main(){
    Heater h1, h2;
    //h1
    cout<<"\nDemonstrating Heater-1:\n";
    h1.show();
    h1.warmer();
    h1.show();
    h1.cooler();
    h1.show();

    //h2
    cout<<"\nDemonstrating Heater-2:\n";
    h2.show();
    h2.cooler();
    h2.show();
    h2.warmer();
    h2.show();
    return 0;
}
