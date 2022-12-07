/*
8.4.2 Activity
Create  a  class  RationalNumber  that  stores  a  fraction  in  its  original  form  (i.e.  without  finding  the
equivalent  floating  pointing  result).  This  class  models  a  fraction  by  using  two  data  members:  an
integer  for  numerator  and  an  integer  for  denominator.  For  this  class,  provide  the  following
functions:
a) A no‐argument constructor that initializes the numerator and denominator of a fraction to
some fixed values.
b) A two‐argument constructor  that initializes  the numerator and denominator  to  the values
sent  from  calling  function.  This  constructor  should  prevent  a  0  denominator  in  a  fraction,
reduce or simplify fractions that are not in reduced form, and avoid negative denominators.
c) A function AddFraction for addition of two rational numbers.
d) A function SubtractFraction for subtraction of two rational numbers.
e) A function MultiplyFraction for subtraction of two rational numbers.
f) A function DivideFraction for division of two rational numbers.
g) Provide the following functions for  comparison of two fractions
    a.  isGreater:  should  return  a  variable  of  type bool  to  indicate  whether  1st  fraction  is
    greater than 2nd or not.
    b.  isSmaller:  should  return  a  variable  of  type bool  to  indicate  whether  1st  fraction  is
    smaller than 2nd or not.
    c.  isGreaterEqual: should return a variable of type bool to indicate whether 1st fraction
    is greater than or equal to 2nd or not.
    d.  isSmallerEqual: should return a variable of type bool to indicate whether 1st fraction
is smaller than or equal to 2nd or not.
h) Provide the following functions to check the equality of two fractions
    e.  isEqual: should return a variable of type bool to indicate whether 1st fraction is equal
    to the  2nd fraction or not.
    f.  isNotEqual: should a true value if both the fractions are not equal and return a false
    if both are equal.
i) Provide the showRN() to display the respective rational number.
NOTE 1: Define all the member functions outside the class (Only in C++).
NOTE  2:  Use  appropriate  special  function  name  for  respective  overloaded  operator  as
given in Table 6.1 (Only in Python).
*/
#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;
public:
    RationalNumber();
    RationalNumber(int n, int d);

    void show() const;
    void input();

    RationalNumber operator + (RationalNumber rn );
    RationalNumber operator - (RationalNumber rn );
    RationalNumber operator * (RationalNumber rn );
    RationalNumber operator / (RationalNumber rn );

    bool operator < (RationalNumber rn) const;
    bool operator <= (RationalNumber rn) const;
    bool operator != (RationalNumber rn) const;
    bool operator == (RationalNumber rn) const;
    bool operator >= (RationalNumber rn) const;
    bool operator > (RationalNumber rn) const;
};
RationalNumber::RationalNumber(): numerator(1), denominator(1) {}
RationalNumber::RationalNumber(int n, int d): numerator(n), denominator(d) {}

void RationalNumber::show()const{
    if(denominator == 0){
        cout<<"Undefined! Denominator can't be zero."<<endl;
        return;
    }
    if (numerator == 0)
        cout<< 0 << endl;
    else if (denominator == 1)
        cout<< numerator << endl;
    else if (numerator == denominator)
        cout<< 1 << endl;
    else if (numerator == denominator)
        cout<< 1 << endl;
    else if( numerator < 0 && denominator < 0)
        cout<< -numerator << " / " << -denominator << endl;
    else if( numerator < 0 && denominator > 0)
        cout<< "-" << -numerator << " / " << denominator << endl;
    else if(numerator > 0 && denominator < 0)
        cout<< "-" << numerator << " / " << -denominator << endl;
    else
        cout<< numerator << " / " << denominator << endl;
}
void RationalNumber::input(){
    cout << "Enter Numerator? "; cin >> numerator;
    cout << "Enter Denominator? "; cin >> denominator;
}

RationalNumber RationalNumber::operator + (RationalNumber rn ){
    int n = ( numerator * rn.denominator) + (denominator * rn.numerator);
    int d = denominator * rn.denominator;
    return RationalNumber(n, d);

}
RationalNumber RationalNumber::operator - (RationalNumber rn ){
    int n = ( numerator * rn.denominator) - (denominator * rn.numerator);
    int d = denominator * rn.denominator;
    return RationalNumber(n, d);

}
RationalNumber RationalNumber::operator * (RationalNumber rn ){
    int n = numerator * rn.numerator;
    int d = denominator * rn.denominator;
    return RationalNumber(n, d);

}
RationalNumber RationalNumber::operator / (RationalNumber rn ){
    int n = numerator * rn.denominator;
    int d = denominator * rn.numerator;
    return RationalNumber(n, d);
}

bool RationalNumber::operator < (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 < rationalNumber2) ? true : false ;
}
bool RationalNumber::operator <= (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 <= rationalNumber2) ? true : false ;
}
bool RationalNumber::operator != (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 != rationalNumber2) ? true : false ;
}
bool RationalNumber::operator == (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 == rationalNumber2) ? true : false ;
}
bool RationalNumber::operator >= (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 >= rationalNumber2) ? true : false ;
}
bool RationalNumber::operator > (RationalNumber rn) const {
    float rationalNumber1 = numerator / denominator;
    float rationalNumber2 = rn.numerator / rn.denominator;
    return (rationalNumber1 > rationalNumber2) ? true : false ;
}

int main(){
    RationalNumber pq1, pq2;
    pq1.input();
    pq2.input();
    pq1.show(); pq2.show();

    cout<<"Adding pq1 and pq2"<<endl;
    RationalNumber pq3;
    pq3 = pq1 + pq2;
    pq3.show();

    cout<<"Subtracting pq2 from pq1" << endl;
    pq3 = pq1 - pq2;
    pq3.show();

    cout<<"Multiplying pq1 and pq2" << endl;
    pq3 = pq1 * pq2;
    pq3.show();

    cout<<"Dividing pq1 with pq2" << endl;
    pq3 = pq1 / pq2;
    pq3.show();

    cout<<"\nComparing pq1 and pq2\n";
    (pq1 > pq2)?
        cout<<"pq1 is greater than pq2" << endl :
        cout<<"pq2 is greater than pq1" << endl ;
    (pq1 < pq2)?
        cout<<"pq1 is less than pq2" << endl :
        cout<<"pq2 is less than pq1" << endl ;
    (pq1 >= pq2)?
        cout<<"pq1 is greater than or equal to pq2" << endl :
        cout<<"pq2 is greater than or equal to pq1" << endl ;
    (pq1 <= pq2)?
        cout<<"pq1 is less than or equal to pq2" << endl :
        cout<<"pq2 is less than or equal to pq1" << endl ;
    (pq1 == pq2)?
        cout<<"pq1 is equal to pq2" << endl :
        cout<<"pq1 is not equal to pq2" << endl ;
    (pq1 != pq2)?
        cout<<"pq1 is not equal to pq2" << endl :
        cout<<"pq1 is equal to pq2" << endl;

    return 0;
}
