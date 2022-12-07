/*
8.4.1 Activity
Create  a  class  called  Distance  containing  two  members  feet  and  inches.  This  class  represents
distance measured in feet and inches. For this class, provide the following functions:
a) A no‐argument constructor that initializes the data members to some fixed values.
b) A 2‐argument constructor to initialize the values of feet and inches to the values sent from
the calling function at the time of creation of an object of type Distance.
c) A showDistance() to show the distance in feet and inches.
d) Overloaded arithmetic operators
    a. operator+ to add two distances: Feet and inches of both objects should add in their
    corresponding members. 12 inches constitute one feet. Make sure that the result of
    addition doesn’t violate this rule.
    b. operator+= for addition of two distances.
i) Overloaded relational operators
    a. operator > should return a variable of type bool to indicate whether 1st distance is
    greater than 2nd or not.
    b. operator < should return a variable of type bool to indicate whether 1st distance is
    smaller than 2nd or not.
    c. operator >= should return a variable of type bool to indicate whether 1st distance is
    greater than or equal to 2nd or not.
    d. operator <=  should return a variable of type bool to indicate whether 1st distance is
    smaller than or equal to 2nd or not.
j) Overloaded equality operators
    a. operator==should return a variable of type bool to indicate whether 1st Distance is
    `
    equal to the  2nd distance or not.
    b. Operator!= should a true value if both the distances are not equal and return a false
    if both are equal.
k) Overloaded operators for pre‐ and post‐ increment. These increment operators should add
a 1 to the inches. Keep track that inch should not exceed 12.
l) Overload  operators  for  pre‐  and  post‐  decrement.  These  decrement  operators  should
subtract  a  1  from  inches.  If  number  of  inches  goes  below  0,  take  appropriate  actions  to
make this value valid.
*/
#include <iostream>
using namespace std;

class Distance{
    private:
        float feet;
        float inches;
    public:
        Distance();
        Distance(float ft, float in);

        void show();
        void input();
        void standardForm();

            //Unary operators overloading!
        Distance operator ++ ();    //pre-inc
        Distance operator ++ (int); //post-inc
        Distance operator -- ();    //pre-dec
        Distance operator -- (int); //post-dec

            //Arithmetic operators overloading!
        Distance operator + (Distance d);

            //Comparison operators overloading!
        bool operator < (Distance d) const;
        bool operator > (Distance d) const;
        bool operator <= (Distance d) const;
        bool operator >= (Distance d) const;
        bool operator == (Distance d) const;
        bool operator != (Distance d) const;

            //Arithmetic Assignment operators overloading!
        void operator += (Distance d);
};

Distance::Distance(): feet(0), inches(0) {}
Distance::Distance(float ft, float in): feet(ft), inches(in) {standardForm();}

void Distance::show(){
    cout<<feet<<"\', "<<inches<<"\'' "<<endl;
}
void Distance::input(){
    cout<<"Enter feet? "; cin>>feet;
    cout<<"Enter inches? "; cin>>inches;
    standardForm();

}
void Distance::standardForm(){
        while(inches >= 12 ){   //for positive inches
            inches -= 12;
            feet++;
        }
        while(inches < 0 ){ //for negative inches
            inches += 12;
            feet--;
        }
}
//Unary operators overloading!
Distance Distance::operator ++ (){
    ++inches;
    standardForm();
    return Distance(feet, inches);
}
Distance Distance::operator ++ (int){
    inches++;
    standardForm();
    return Distance(feet, inches);
}
Distance Distance::operator -- (){
    --inches;
    standardForm();
    return Distance(feet, inches);
}
Distance Distance::operator -- (int){
    inches--;
    standardForm();
    return Distance(feet, inches);
}
//Arithmetic operators overloading!
Distance Distance::operator + (Distance d) {
    float ft = feet + d.feet;
    float in = inches + d.inches;
    while(in >= 12 ){
            in -= 12;
            ft++;
        }
    return Distance( ft, in );
}
//Comparison operators overloading!
bool Distance::operator < (Distance d) const {
    float distanceInFeet1 = feet + inches/12;
    float distanceInFeet2 = d.feet + d.inches/12;
    return (distanceInFeet1 < distanceInFeet2 )? true : false ;
}
bool Distance::operator > (Distance d) const {
    float distanceInInches1 = feet*12 + inches;
    float distanceInInches2 = d.feet*12 + d.inches;
    return (distanceInInches1 > distanceInInches1 ) ? true : false;
}
bool Distance::operator <= (Distance d) const{
    float distanceInInches1 = feet*12 + inches;
    float distanceInInches2 = d.feet*12 + d.inches;
    return (distanceInInches1 <= distanceInInches1 ) ? true : false;
}
bool Distance::operator >= (Distance d) const{
    float distanceInFeet1 = feet + inches/12;
    float distanceInFeet2 = d.feet + d.inches/12;
    return (distanceInFeet1 >= distanceInFeet2 )? true : false ;
}
bool Distance::operator == (Distance d) const {
    float distanceInFeet1 = feet + inches/12;
    float distanceInFeet2 = d.feet + d.inches/12;
    return (distanceInFeet1 == distanceInFeet2 )? true : false ;
}
bool Distance::operator != (Distance d) const {
    float distanceInFeet1 = feet + inches/12;
    float distanceInFeet2 = d.feet + d.inches/12;
    return (distanceInFeet1 != distanceInFeet2 )? true : false ;
}

//Arithmetic Assignment operators overloading!
void Distance::operator += (Distance d){
    feet += d.feet;
    inches += d.inches;
    standardForm();
}

int main(){
    Distance d1(3, 12), d2(12, 0);
    cout<<"Showing d1 and d2" <<endl;
    d1.show();
    d2.show();

    Distance d3;
    cout<<"\nAdding d1 and d2\n";
    d3 = d1 + d2;
    d3.show();

    d3 += d1;
    cout<<"\nAdding d3 and d1\n";
    d3.show();

    cout<<"\nComparing d1 and d2\n";
    (d1 > d2)?
        cout<<"d1 is greater than d2" << endl :
        cout<<"d2 is greater than d1" << endl ;
    (d1 < d2)?
        cout<<"d1 is less than d2" << endl :
        cout<<"d2 is less than d1" << endl ;
    (d1 >= d2)?
        cout<<"d1 is greater than or equal to d2" << endl :
        cout<<"d2 is greater than or equal to d1" << endl ;
    (d1 <= d2)?
        cout<<"d1 is less than or equal to d2" << endl :
        cout<<"d2 is less than or equal to d1" << endl ;
    (d1 == d2)?
        cout<<"d1 is equal to d2" << endl :
        cout<<"d1 is not equal to d2" << endl ;
    (d1 != d2)?
        cout<<"d1 is not equal to d2" << endl :
        cout<<"d1 is equal to d2" << endl;

    cout<<"\nPre incrementing d1\n";
    ++d1; d1.show();
    cout<<"\nPost incrementing d1\n";
    d1++; d1.show();

    return 0;
}
