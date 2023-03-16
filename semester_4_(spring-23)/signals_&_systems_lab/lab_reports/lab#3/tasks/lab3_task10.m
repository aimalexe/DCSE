%{
Create an m?file that inputs a number from user and then finds out the factorial of that number. 
%}

clc;
clear;

num = input('Enter a number? ');
factorial = 1;

for i=1 : num
    factorial = factorial * i;
end

factorial