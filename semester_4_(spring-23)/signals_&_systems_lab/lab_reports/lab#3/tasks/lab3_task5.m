%{
Rewrite the following statements to use only one if statement. 
 if x < y 
    if z < 5 
        w = x*y*z 
    end 
end 
%}
clc;
clear;

 %For satisfying condition initializing variables as:
 x = 2;
 y = 3;
 z = 4;

if x < y && z < 5
    w = x * y * z 
end