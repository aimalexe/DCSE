//4.3.8 Example: Custom Deep Copy Constructor
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

class Students{
private:
    char* name;
    int age;
    float gpa;
public:
    Students():name(""), age(0), gpa(0.00) {}
    Students(char na[], int ag, float gp):name(na), age(ag), gpa(gp) {}
    Students(const Students &s){
        cout << "\nIn Custom Copy Constructor [Deep]" << endl;
        int nameLength = strlen(s.name);
        name = new char [nameLength + 1];   // to include '/0'
        strcpy(name, s.name);
        age = s.age;
        gpa = s.gpa;
    }
    ~Students(){
        cout << "Terminating object." << endl;
        delete[] name;
    }
    void show(){
         cout<<"Student Data"<<endl;
         cout<<"Name: "<<name<<"\tAddress: "<<(void *)name<<endl;
         cout<<"Age: "<<age<<endl;
         cout<<"GPA: "<<gpa<<endl<<endl;
    }
};

int main(){
    Students s1("Aimal Khan", 21, 3.78);
    s1.show();

    Students s2(s1);
    s2.show();

    Students s3(s2);
    s2.show();

    return 0;
}
