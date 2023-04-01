%{
Determine the complex conjugate of the exponential signal given in above example and plot its 
real and imaginary portions.
%}

clc;
clear;
close all;

n = 0: 2/10 : 10;
k = 5;
a = pi/2;
sig = k * exp(a * n * i);

conj_sig = conj(sig);

% plot the real part
subplot(2,1,1)
stem(n, real(conj_sig), 'filled')
title('Real part of cojugate complex exp') 
xlabel('sample #')
ylabel('signal amplitude') 
grid

% plot the imaginary 
subplot(2,1,2)
stem(n, imag(conj_sig), 'filled') 
title('Imaginary part of conjugate complex exp') 
xlabel('sample #')
ylabel('signal amplitude') 
grid