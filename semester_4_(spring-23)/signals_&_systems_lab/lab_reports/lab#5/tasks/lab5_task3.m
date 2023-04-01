%{
Take two complex number and compute z1 +z2 and display the results numerically using zprint.
%}

clc;
clear;

z1 = input('Enter a Complex number z1?');
z2 = input('Enter a Complex number z2?');

sum = z1 + z2;

[real,imaginary, magnitude, angleInRadian, angleIndegrees, conjugate, inverse] = zprint(sum);

real,imaginary, magnitude, angleInRadian, angleIndegrees,conjugate, inverse