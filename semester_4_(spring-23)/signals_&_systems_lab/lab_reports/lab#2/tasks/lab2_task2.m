%{
Generate two 2500 sampled random discrete time signals (1 dimensional) using rand() function 
i.e. rand(1, 2500). Write a program to add the two such random signals together using simple 
vector addition.
%}

clc;
clear;

%Generating random matrices
matrix1 = rand(1, 100);
matrix2 = rand(1, 100);

% Adding both matrices
matrixAddition = matrix1 + matrix2