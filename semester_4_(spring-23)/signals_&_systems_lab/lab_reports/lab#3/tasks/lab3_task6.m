%{
Using for loop, generate the cube of the first ten integers. 
%}
clc;
clear;

for i = 1 : 10
    cube = i ^ 3;
    fprintf('Cube of %d is: %d\n', i, cube);
end