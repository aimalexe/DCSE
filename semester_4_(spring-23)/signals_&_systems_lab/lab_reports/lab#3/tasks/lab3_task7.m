%{
Add the following two matrices using for loop.  
%}
clc;
clear;
a = [ 5 12 3; 9 6 5; 2 2 1];
b = [ 2 1 9; 10 5 6; 3 4 2];
for i = 1 : size(a,1)
    for j = 1 : size(a,2)
        c(i,j) = a(i,j) + b(i,j);
    end
end
disp('The sum of matrices are: ');
disp(c);
