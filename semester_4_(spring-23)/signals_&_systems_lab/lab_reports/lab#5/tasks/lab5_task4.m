%{
Take two complex numbers and compute z1z2 and z1/z2. Use zprint to display the results 
numerically.
%}

clc;
clear;

z1 = input('Enter a Complex number z1?');
z2 = input('Enter a Complex number z2?');

prod = z1 * z2;

[real,imaginary, magnitude, angleInRadian, angleIndegrees, conjugate, inverse] = zprint(prod);
disp('\nShowing prod of z1 and z2 through zprint')
real,imaginary, magnitude, angleInRadian, angleIndegrees,conjugate, inverse

div = z1 / z2;
[real,imaginary, magnitude, angleInRadian, angleIndegrees, conjugate, inverse] = zprint(div);
disp('\nShowing  z1/z2 through zprint')
real,imaginary, magnitude, angleInRadian, angleIndegrees,conjugate, inverse