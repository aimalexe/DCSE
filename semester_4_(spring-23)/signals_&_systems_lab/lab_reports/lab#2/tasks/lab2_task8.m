%{
The end command is used to access the last row or column of a matrix. Use the end command 
to delete and update the last row and column of the following matrix.
Matrix A = [3 23 34 12 34 5 56 23; 12 34 34 32 23 23 45 1; 67 23 2 4 4 5 6 456; 4 5 1 1 2 34 45 56; 67 67 45 67 78 7 8 5; 6 35 5 3 5 56 7 8]
%}
clc;
clear;

matrix_A = [3 23 34 12 34 5 56 23;
    12 34 34 32 23 23 45 1;
    67 23 2 4 4 5 6 456;
    4 5 1 1 2 34 45 56;
    67 67 45 67 78 7 8 5;
    6 35 5 3 5 56 7 8]

%updating the last row.
matrix_A(:, end) = [1 2 3 4 5 6];

% Updating last row 
matrix_A(end, :) = [ 1 2 3 4 5 6 7 8]
