%{
Perform the following commands on various matrices and comment on each. 
 >> ~A  
 >> A&B  
 >> A & ~B  
 >> A | B  
 >> A | ~A 
%}
clc;
clear;

A = [ 1 2 3; 4 5 6; 7 8 9];
B = [ 9 8 7; 6 5 4; 3 2 1];

C = ~A
D = A&B
E = A & ~B
F = A | B
G = A | ~A