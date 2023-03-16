%{
For the arrays x and y given below, write matlab code to find all the elements in x that are greater than the
corresponding elements in y. 
x = [?3, 0, 0, 2, 6, 8] y = [?5, ?2, 0, 3, 4, 10] 
%}
clc;
clear;

x = [-3  0 0 2 6 8];
y = [-5 -2 0 3  4  10];

disp('Elements in x that are greater than the corresponding elements in y are shown with 1');
z = (x > y)
