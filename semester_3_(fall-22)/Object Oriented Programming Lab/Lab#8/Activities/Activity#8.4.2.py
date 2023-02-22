"""
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
"""

class RationalNumber:
    pass