%{
Generate the complex valued signal and plot its magnitude, phase, the real part, and the 
imaginary part in separate subplots.
y(n) = exp (-0.2 + j0.5n) , ?10?n?10
%}
clc;
clear;
close all;

n = -10 : 1 : 10;
sig = exp(-0.2 + 0.5 * i * n);

% plot the real part
subplot(2,2,1)
stem(n, real(sig), 'filled', 'r')
title('Real part of complex exp') 
grid

% plotting the imaginary part
subplot(2,2,3)
stem(n, imag(sig), 'filled', 'g') 
title('Imaginary part of complex exp') 
grid

% plotting the magnitude
subplot(2,2,2)
stem(n, abs(sig), 'filled', 'b') 
title('Magnitude of complex exp') 
grid

% plotting the phase
subplot(2,2,4)
stem(n, angle(sig), 'filled', 'y') 
title('Phase of complex exp') 
grid

