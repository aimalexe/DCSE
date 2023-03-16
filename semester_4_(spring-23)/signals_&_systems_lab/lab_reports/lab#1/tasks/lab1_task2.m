%{
Create an M-File to prove any five expressions from the following
trignometric equations
%}

clc;
clear;

% variables to use in expressions
a=45;
b=45;

tic
% Expression1
lhs = sin(a + b)
rhs = sin(a)*cos(b)+ cos(a)*sin(b)
disp('--------------------------------------')

% Expression2
lhs = cos(a + b)
rhs = cos(a)*cos(b) - sin(a)*sin(b)
disp('--------------------------------------')

% Expression3
lhs = sin(a)*sin(b)
rhs = 0.5*(cos(a - b) - cos(a + b))
disp('--------------------------------------')

% Expression4
lhs = tan( a + b)
rhs = (tan(a)+ tan(b)) / (1 - tan(a)*tan(b) )
disp('--------------------------------------')

% Expression5
lhs = cos(a) + cos(b)
rhs = 2*cos( 0.5 *( a + b )) * cos( 0.5 *( a - b ) )
toc