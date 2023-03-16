%{
Given the matrices:
A=[-12,34,61,-9;65,78,90,12; 14,78,45,12; 60,25,3,8]
B=[34,67,8,9; 12,-91,12,9; 89,-8,0,2; 16,9,23,67]
Find the following:
1) Array addition; store the result in matrix C 
2) Array subtraction; store the result in matrix D 
3) Array multiplication using .* operator; store the result in matrix E 
4) Array division using ./ operator; store the result in matrix F 
5) Array exponentiation using .^ operator; store the result in matrix G 
6) Take sin of A and store the result in H, Take sqrt of B and store the result in I. Find H*I
and store the result in J.
%}

clc;
clear;

A=[-12,34,61,-9;65,78,90,12; 14,78,45,12; 60,25,3,8]
B=[34,67,8,9; 12,-91,12,9; 89,-8,0,2; 16,9,23,67]

disp('A + B')
C = A + B

disp('A - B')
D = A - B

disp('A .* B')
E = A .* B

disp('A ./ B')
F = A ./ B

disp('A .^ B')
G = A .^ B

disp('sinA')
H = sin(A)

disp('squarerootB')
I = sqrt(B)

disp('sinA + sqrtB')
J = H * I