%{
Implement the Pythagoras theorem in MatLab that takes input from the user.
%}
clc;
clear;
 % taking base and perp from user.
base = input('Enter base? ');
perp = input('Enter perpendicular? ');

% calculating hypoteneus.
hyptSquare = base^2 + perp^2;
hypt = sqrt(hyptSquare);
disp('hypoteneus is ');
disp(hypt);