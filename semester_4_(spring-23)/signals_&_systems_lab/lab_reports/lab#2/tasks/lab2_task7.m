%{
Given the following matrix:
?3 5
4 8
Find the following:
1) Column?wise sum of all elements of A using sum function; for information about sum 
function, type help sum in matlab 
2) Column?wise product of all elements of A using prod function; for information about 
prod function, type help prod in matlab 
3) Length of matrix A 
4) Size of matrix A 
%}

clc;
clear;

matrixA = [-3 5; 4 8]

% Column?wise sum of all elements of A using sum function
columnWiseSum = sum(matrixA, 1)

% Column?wise product of all elements of A using prod function
columnWiseProduct = prod(matrixA, 1)

%Length of matrix A 
lengthOfMAtrixA = length(matrixA)

%Size of matrix A 
sizeOfMAtrixA = size(matrixA)