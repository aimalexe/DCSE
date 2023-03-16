%{
For 0 < a ? 16, find the values of C defined as follows: 
and b = 12.   
%}
clc;
clear;

b = 12;
c = 0;
a = input('Enter value for a? ');
if (a >= 1 && a <= 8)
    c = 4 * a * b;
elseif ( a > 8 && a <= 16)
    c = a*b;
else
    disp('Value is not in between 0 and 16');
end

disp('Value of c is: ');
disp(c);