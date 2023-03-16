%{
Solve Task 10 by taking the equations from user.
%}
clc;
clear;

% Taking inputs from user!
disp('Enter equation?')
a1 = input('Enter a1? ');
b1 = input('Enter b1? ');
c1 = input('Enter c1? ');

a2 = input('Enter a2? ');
b2 = input('Enter b2? ');
c2 = input('Enter c2? ');

a3 = input('Enter a3? ');
b3 = input('Enter b3? ');
c3 = input('Enter c3? ');

disp('Enter the Constants for your equations')
q1 = input('Enter const1? ');
q2 = input('Enter const2? ');
q3 = input('Enter const3? ');

disp('You entered this matrix: ');
coefficient = [a1 b1 c1; a2 b2 c2; a3 b3 c3]

disp('The constants matrix is: ');
constants = [q1; q2; q3]

disp('The Three unknowns are: ');
X = inv(coefficient) * constants