%{
MATLAB has functions to round floating point numbers to integers. These are round, fix, 
ceil, and floor. Test how these functions work. Determine the output of the following:
>> f = [?.5 .1 .5]; 
>> round(f) 
>> fix(f) 
>> ceil(f) 
>> floor(f)
%}

clc;
clear;

a = [.5 .9 .1]

disp('ceil: ')
ceil(a)

disp('floor: ')
floor(a)

disp('round: ')
round(a)

disp('fix: ')
fix(a)
