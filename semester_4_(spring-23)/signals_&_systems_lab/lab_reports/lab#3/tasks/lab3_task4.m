%{
For the values of integer a going from 1 to 10, using separately the methods of if syntax and the Boolean
alternative expressions, find the values of C if:    
%}
clc;
clear;

c = 0;
a = input('Enter value for a? ');

if (a < 3)
    c = a ^ 2;
elseif(a >= 3 && a < 7)
    c = a + 3;
elseif(a > 7)
    c = a;
end

disp('Value of c is: ');
disp(c);