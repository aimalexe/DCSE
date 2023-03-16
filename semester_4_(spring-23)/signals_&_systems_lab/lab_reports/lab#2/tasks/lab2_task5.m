%{
Type the given matrix in matlab:
3 7 ?4 12
-5 9 10 2
6 13 8 11
 15 5 4 1
Find the following:
1) Create 4x3 array B consisting of all elements in the second through fourth columns of A 
2) Create 3x4 array C consisting of all elements in the second through fourth rows of A 
3) Create 2x3 array D consisting of all elements in the first two rows and the last three 
columns of A
%}

clc;
clear;

matrixA = [3 7 -4 12;-5 9 10 2;6 13 8 11;15 5 4 1]

%Creating 4x3 array B consisting of all elements in the second through fourth columns of A 
matrixB = matrixA(:,2:4)

%Create 3x4 array C consisting of all elements in the second through fourth rows of A
matrixC = matrixA(2:4, :)

%Create 2x3 array D consisting of all elements in the first two rows and the last three columns of A
matrixD = matrixA(1:2, 2:4)