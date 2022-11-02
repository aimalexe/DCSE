
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

class Employ{
    private:
        char* name;
        char* department;
        float salary;
        float service;

    public:
         Employ():name(" "),department(" "), salary(0.00), service(0.00) {}
         Employ(char na [], char de [], float sa, float se):name(na), department(de), salary(sa), service(se) {}
         Employ(const Employ &e){
            cout << "\nIn Custom Copy Constructor [Deep]" << endl;
            int nameLength = strlen(e.name);
            int departmentLength = strlen(e.department);
            name = new char [nameLength + 1]; // '/0'
            department = new char [departmentLength + 1];
            strcpy(name, e.name);
            strcpy(department, e.department);
            salary = e.salary;
            service = e.service;
         }
         void showEmploy ()const {
             cout<<"Employ Data"<<endl;
             cout<<"Name:\t"<<name<<"\tAddress: "<<(void *)name<<endl;
             cout<<"Department:\t"<<department<<"\tAddress: "<<(void *)department<<endl;
             cout<<"Salary:\t"<<salary<<endl;
             cout<<"Service of years:\t"<<service<<endl<<endl;
         }
         void setEmploy(){
             int nameLength = strlen(name);
             name = new char [nameLength + 1];
            cout<<"Enter Employ's name:\t";
            gets(name);
            int departmentLength = strlen(department);
            department = new char [departmentLength + 1];
            cout<<"Enter Employ's Department:\t";
            cin>>department;
            gets(department);
            cout<<"Enter Employ's Salary:\t";
            cin>>salary;
            cout<<"Enter Employ's Service:\t";
            cin>>service;
         }
         ~ Employ(){
             cout<<"Object destroyed!";
             delete [] name;
             delete [] department;
         }
};

int main(){
    //Employ e1("Aimal Khan", "DCSE", 49878.34, 21.2);
    Employ e1;
    e1.showEmploy();
    e1.setEmploy();
    e1.showEmploy();

    Employ e2 (e1);
    e2.showEmploy();

    Employ e3 = e2;
    e3.showEmploy();

    return 0;
}
