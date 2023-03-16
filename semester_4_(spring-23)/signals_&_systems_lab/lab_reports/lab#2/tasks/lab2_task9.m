%{
Try the following commands in MatLab and comment on them:
(i) A(3,end) 
(ii) A(:)
(iii) A(: , end)
(iv) Y = linspace(20,100) 
(v) Y = linspace(20,100,50)
%}

clc;
clear;

matrix_A = [1 22 34 52 22; 12 87 76 90 68; 45 63 78 82 12; 365 65 28 98 94]

% accessing last element of 3rd row
matrix_A(3, end)

% converting matrix A to column matrix
matrix_A(:)

% Linearly spacced vectors.
% Generates a row vector of 100 (default) linearly equally spaced points between 20 and 100.
Y = linspace(20, 100)

% Generates a row vector of 50 linearly equally spaced points between 20 and 100.
Y = linspace(20, 100, 50)