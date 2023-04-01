%{
Write matlab function zprint, which takes a complex number and returns it real part, imaginary 
part, magnitude, phase in radians, and phase in degrees.
%}

clc;
clear;

x = input('Enter a Complex number?');
[real,imaginary, magnitude, angleInRadian, angleIndegrees] = zprint(x);

imaginary, real, magnitude, angleInRadian, angleIndegrees