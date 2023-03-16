%{
Write a program to generate a new matrix B from the matrix A given below such that each 
column in the new matrix except the first one is the result of subtraction of that column from
the previous one i.e. 2nd new column is the result of subtraction of 2nd column and 1st column 
and so on. Copy the first column as it is in the new matrix.
13 6 9
1 4 8
2 8 17
%}

clc;
clear; 

MatrixA = [13 6 9; 1 4 8; 2 8 17];
MAtrixB = [MatrixA(:,1),MatrixA(:,1)-MatrixA(:,2),MatrixA(:,2)-MatrixA(:,3)]
