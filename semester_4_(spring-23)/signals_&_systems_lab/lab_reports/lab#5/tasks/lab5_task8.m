%{
Multiply the two discrete signals x1=5 exp (i*n*pi/4) and x2= a * exp(jn) (use point?by?point 
multiplication of the two signals). Plot the real as well as the imaginary parts for 0<a<1 and 
a>1.
%}
clc;
clear;
close all;

n = 0: 0.3: 2;

amp = 5;
sig1 = amp * exp( i * n * pi / 4);
sig2 = amp * exp( i * n);
prod = sig1 .* sig2;

subplot(2,1,1);
stem(n, real(prod), 'filled');
title('Real part of product of sig1 and sig2');
xlabel('sample #');
ylabel('signal amplitude')
grid

subplot(2,1,2);
stem(n, imag(prod), 'filled');
title('Imaginary part of product of sig1 and sig2');
xlabel('sample #');
ylabel('signal amplitude')
grid