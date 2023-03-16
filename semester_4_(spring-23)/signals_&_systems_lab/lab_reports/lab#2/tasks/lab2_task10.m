%{
Use the inverse (inv(A)) function to find the inverse of A for finding the unknowns for 
the Linear equation.
x + 2y + 3z = 1
4x + 5y + 6z = 2 
7x + 8y = 1 
%}
clc;
clear;

% Coefficient matrix;
A = [1 2 3 ; 4 5 6; 7 8 0];

% Constants matrix
B = [1;2;1];

% Finding unknowns matrix
X = inv(A) * B