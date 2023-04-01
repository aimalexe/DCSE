%{
Compute the conjugate ? (i.e. z_conj [give variable name]) and the inverse 1/z (i.e. z_inv [give 
variable name]) for any complex number z. Display the results numerically with zprint.
%}

clc;
clear;

x = input('Enter a Complex number?');

[r, i, m, rad, deg, conjugate, inverse] = zprint(x);
conjugate, inverse