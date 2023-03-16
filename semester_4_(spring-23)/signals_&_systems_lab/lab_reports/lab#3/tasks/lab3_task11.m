%{
Create an m?file that takes two vectors from user. Make sure that the second vector taken is of the same size
as the first vector (Hint: use while loop). In a while loop, generate a third vector that contains the sum
of the squares of corresponding entries of both the vectors. 
%}
clc;
clear;
rows = input('Enter rows? ');
cols = input('Enter columns? ');
 
i = 1;
while i <= rows
     j = 1;
    while j <= cols
        matA(i, j) = input('Input Element for matrix A? ');
        matB(i, j) = input('Input Element for matrix B? ');
        
        matC(i, j) = matA(i,j)^2 + matB(i, j)^2;
        
        i = i +1;
        j = j + 1;
    end
end
matC